#!/usr/bin/env python3

import requests

from utils import generate_developer_token

TEST_URL = 'https://api.music.apple.com/v1/test'

ROOT_PATH = 'https://api.music.apple.com/v1'

DEVELOPER_TOKEN = generate_developer_token()
headers = {'Authorization': f'Bearer {DEVELOPER_TOKEN}'}

# response = requests.get(ROOT_PATH + '/me/library/artists', headers=headers)
response = requests.get(TEST_URL)

print(response.status_code)
print(response.headers)
print(response.text)
