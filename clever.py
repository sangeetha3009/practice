import json
import requests
import sys

try:
    r=requests.get('https://api.clever.com/v1.1/districts/4fd43cc56d11340000000005/sections', headers={'Authorization':'Bearer DEMO_TOKEN'})
    section_json=json.loads(r.text)
except Exception as e:
    print "Exception in api access",e

numSections=0
numStudents=0

try:
    for section in section_json['data']:
        numSections+=1
        numStudents+=len(section['data']['students'])
except Exception as e:
    print "Exception in parsing json ",e    

try:
    avgStudents=float(numStudents)/float(numSections)
    print "Average Students per section", avgStudents   
except Exception as e:
    print "Exception in average calculation ",e


sys.exit(0)
