#!/usr/bin/env python

import logging, sys, requests, json, pathlib, os
from dotenv import load_dotenv
from bs4 import BeautifulSoup

dotenv_path = pathlib.Path(__file__).parent/'.env'
load_dotenv(dotenv_path)

# \033 = \e = ESC
RED = '\033[31m'
BOLD = '\033[1m'
RESET = '\033[0m'

# logging.basicConfig(filename=f"{__file__}./log.txt", level=logging.INFO, filemode='w')
logger = logging.getLogger(__name__)
handler = logging.StreamHandler(sys.stderr)
logger.addHandler(handler)

doi = ""
while len(doi) == 0:
  print("Enter DOI: ", end='')
  doi = input().strip() # https://doi.org/xxxx or xxxx

print(f"Retrieving {doi}...")

if doi.startswith("https://doi.org/"):
  doi = doi[16:]
crossref_url = "https://api.crossref.org/works/" + doi
print(f"crossref_url: {crossref_url}")

crossref_response = requests.get(crossref_url)
if crossref_response.status_code != 200:
  logger.error(f"paper_retriever: Error: Unable to fetch data from {crossref_url}. Status code: {crossref_response.status_code}")
  sys.exit(1)
data = json.loads(crossref_response.text)
# p = pathlib.Path("crossref_response.txt").write_text(json.dumps(data, indent=2))


title = ""
if "title" in data["message"]:
  title = data["message"]["title"][0]
  print(f"Title: {title}")
else:
  logger.warning("title not found! find it by yourself.")


abstract_content = ["abstract here"]
if "abstract" in data["message"]:
  s = BeautifulSoup(data["message"]["abstract"], "html.parser")
  abstract = s.find_all("jats:p")
  abstract_content = [x.text for x in abstract]
  abstract_length = sum([len(text) for text in abstract_content])
  print(f"abstract found, the length is {abstract_length}.")
  if abstract_length > 2000:
    logger.warning(f"the length exceed the limit. get whole sentence manually.")
    abstract_content = []
else:
  logger.warning(f"{RED}{BOLD}abstract not found! find it by yourself.{RESET}")


notion_url = "https://api.notion.com/v1/pages"
notion_api_key = os.environ['NOTION_API_KEY']
notion_headers = {
  "accept": "application/json",
  "Notion-Version": "2022-06-28",
  "content-type": "application/json",
  "Authorization": "Bearer " + notion_api_key
}
notion_database_id = os.environ['NOTION_DB_ID']

notion_payload = {
  "parent": {
    "database_id": notion_database_id
  },
  "properties": {
    "Title": {
      "title": [{
        "text": {
          "content": title
        }
      }],
    },
    "Status": {
      "select": {
        "name": "Not started"
      }
    },
    "doi": {
        "url": f"https://doi.org/{doi}"
    }
  },
  "children": [
    {
      "object": 'block',
      "type": 'heading_1',
      "heading_1": {
        "rich_text": [{
          "type": "text",
          "text": {
            "content": "Abstract",
          }
        }]
      }
    }
  ]
}

for p in abstract_content:
  notion_payload["children"].append(
    {
      "object": 'block',
      "type": 'callout',
      "callout": {
        "rich_text": [{
          "type": "text",
          "text": {
            "content": p,
          }
        }],
        "icon": {
          "emoji": "🗒"
        }
      }
    }
  )

notion_response = requests.post(notion_url, headers=notion_headers, json=notion_payload)
if notion_response.status_code != 200:
  logger.error(f"Error: Unable to post data to {notion_url}. Status code: {notion_response.status_code}")
  logger.error(f"Response:\n{notion_response.json()}")
  sys.exit(1)
print('paper_reetriever.py successfully finished!')
