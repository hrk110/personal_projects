#!/bin/bash

# shellcheck disable=SC1090
source ~/personal_projects/tools_for_Notion/paper_retriever/venv/bin/activate

python ~/personal_projects/tools_for_Notion/paper_retriever/paper_retriever.py

deactivate
