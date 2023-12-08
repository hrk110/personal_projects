import sys, pathlib, requests, os
from bs4 import BeautifulSoup

url = "https://api.notion.com/v1/pages"
api_key = os.environ['NOTION_API_KEY']
headers = {
  "accept": "application/json",
  "Notion-Version": "2022-06-28",
  "content-type": "application/json",
  "Authorization": "Bearer " + api_key
}
database_id = os.environ['NOTION_DB_ID']

soup = BeautifulSoup(pathlib.Path(sys.argv[1]).read_text(), "html.parser")
title = soup.find("div", attrs={"class": "bookTitle"}).text.strip()
noteList = soup.find_all("div", attrs={"class": "noteText"})

payload = {
  "parent": {
    "database_id": database_id
  },
  "properties": {
    "Name": {
      "title": [{
        "text": {
          "content": title
        }
      }],
    },
    "Status": {
      "select": {
        "name": "finished"
      }
    }
  },
  "children": []
}

for note in noteList:
  payload["children"].append(
    {
      "object": 'block',
      "type": 'quote',
      "quote": {
        "rich_text": [{
          "type": "text",
          "text": {
            "content": note.text.strip()
          },
          "annotations": {
            "italic": True
          }
        }]
      }
    }
  )
  payload["children"].append(
    {
      "type": "paragraph",
      "paragraph": {
        "rich_text": [{
          "type": "text",
          "text": {
            "content": "",
          }
        }],
      }
    }
  )
  payload["children"].append(
    {
      "type": "divider",
      "divider": {}
    }
  )
  ## note

response = requests.post(url, headers=headers, json=payload)