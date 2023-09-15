import logging, sys, requests, json, pathlib
from bs4 import BeautifulSoup

logging.basicConfig(filename='./log.txt', level=logging.INFO, filemode='w')
logging.info('Script paper_reetriever.py started')

print("Enter DOI:\t")
doi = input().strip() # https://doi.org/xxxx or xxxx
print(f"Retrieving {doi}...")

if doi.startswith("https://doi.org/"):
  doi = doi[16:]
crossref_url = "https://api.crossref.org/works/" + doi
logging.info(f"crossref_url: {crossref_url}")

crossref_response = requests.get(crossref_url)
if crossref_response.status_code != 200:
  logging.error(f"Error: Unable to fetch data from {crossref_url}. Status code: {crossref_response.status_code}")
  sys.exit(1)
data = json.loads(crossref_response.text)
p = pathlib.Path("crossref_response.txt").write_text(json.dumps(data, indent=2))


title = ""
if "title" in data["message"]:
  title = data["message"]["title"][0]
  logging.info(f"title: {title}")
else:
  logging.warning("title not found! find it by yourself.")


abstract_content = ["abstract here"]
if "abstract" in data["message"]:
  s = BeautifulSoup(data["message"]["abstract"], "html.parser")
  abstract = s.find_all("jats:p")
  abstract_content = [x.text for x in abstract]
  logging.info("abstract added")
else:
  logging.warning("abstract not found! find it by yourself.")


notion_url = "https://api.notion.com/v1/pages"
notion_api_key = "secret_soxEiQL6nGV6AG9tZPYYPRe6gtWKofqvcjVhtJ1EOGS"
notion_headers = {
  "accept": "application/json",
  "Notion-Version": "2022-06-28",
  "content-type": "application/json",
  "Authorization": "Bearer " + notion_api_key
}
notion_database_id = "a2bcd4ec8ff843d8b60561e731a461e8"

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
        "name": "In progress"
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

# notion_payload["children"].extend([
#   {
#     "object": 'block',
#     "type": "paragraph",
#     "paragraph": {
#       "rich_text": [{
#         "type": "text",
#         "text": {
#           "content": "",
#         }
#       }]
#     }
#   },
#   {
#     "object": 'block',
#     "type": 'heading_1',
#     "heading_1": {
#       "rich_text": [{
#         "type": "text",
#         "text": {
#           "content": "Important notes",
#         }
#       }]
#     }
#   }]
# )

notion_response = requests.post(notion_url, headers=notion_headers, json=notion_payload)
if notion_response.status_code != 200:
  logging.error(f"Error: Unable to post data to {notion_url}. Status code: {notion_response.status_code}")
  sys.exit(1)
logging.info('Script paper_reetriever.py successfully finished')
