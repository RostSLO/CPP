import http.client
import json

conn = http.client.HTTPSConnection("moviesdatabase.p.rapidapi.com")

headers = {
    'X-RapidAPI-Key': "8bf0871ea3msh8bbb7d0dd036a04p15f9cajsn0e547477cf42",
    'X-RapidAPI-Host': "moviesdatabase.p.rapidapi.com"
}

conn.request("GET", "/titles/search/title/Iron%20Man?exact=true&info=base_info&titleType=movie", headers=headers)

res = conn.getresponse()
data = res.read()

with open('data.json', 'w') as f:
    json.dump(data.decode("utf-8"), f)
print(data.decode("utf-8"))