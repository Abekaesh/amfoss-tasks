# importing necessary modules
import requests
import argparse
import json

parser = argparse.ArgumentParser(description = "To fetch the image")
parser.add_argument("data",type = str, help = "Enter the api key")
parser.add_argument("id",type = int, help = "Enter the id ")
args = parser.parse_args()

api = args.data
ID = args.id

url = "https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos?earth_date=2015-6-3&api_key="+api
r = requests.get(url)
data = json.loads(r.text)

# looping to search the photo id
for i in range(len(data["photos"])):
    #if user input id and id stored in data are same, we can get the link of the img
    if ID == data["photos"][i]["id"]:
        img = data["photos"][i]["img_src"]
        # downloading the img
        img_download = requests.get(img)
        file = open("sample_image.png", "wb")
        file.write(img_download.content)
        file.close()
        break
