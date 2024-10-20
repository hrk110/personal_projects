import sys
from datetime import datetime, timedelta
from joserfc import jwt

def generate_developer_token(key_identifier, team_ID, private_key):
  """Generate encoded string of developer token.

  Parameters
  ----------
  key_identifier : str
      10-character key identifier (kid) key, obtained from your developer account
  team_ID : str
      10-character Team ID, obtained from your developer account
  private_key : str
      your MusicKit private key

  Returns
  -------
  str
      encoded developer token
  """
  # TODO: validate arguments here

  header = {
    'alg': 'ES256',
    'kid': key_identifier,
  }
  claims = {
    'iss': team_ID,
    'iat': datetime.now().strftime('%s'),
    'exp': (datetime.now() + timedelta(seconds=15777000)).strftime('%s')
  }

  token = jwt.encode(
    header=header,
    claims=claims,
    key=private_key,
    algorithms=['ES256']
  )

  return token

def main(argv):
  developer_token = generate_developer_token(argv[1], argv[2], argv[3])
  # TODO test code here

if __name__ == '__main__':
  sys.exit(main(sys.argv))

