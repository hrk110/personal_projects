# Tools for Notion

## Caution

Before using these tools, be sure to complete the following steps:

- Activate the virtual environment for each tool.

  1. `python -m venv .venv`
  2. `source .venv/bin/activate`
  3. `pip install -r requirements.txt`

- Set Notion API Keys

  put `.env` in the current directory. the contents should be:
  ```
  NOTION_API_KEY="secret_xxxx..."
  NOTION_DB_ID="xxx..."
  ```

  - internal access token
    - ref. https://developers.notion.com/docs/authorization#internal-integration-auth-flow-set-up
  - database ID
    - ref. https://developers.notion.com/docs/working-with-databases

- Generating symlink to the directory in which html files from Kindle are stored may be helpful.

## Usage

- `python kindle_highlights.py html_file`
- `python paper_retriever.py`

## Resources

- About conda environment: [https://conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html]


