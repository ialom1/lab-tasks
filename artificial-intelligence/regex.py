import re

emailrx = r'([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})'
email = "ialom@gmail.com"

phonerx = r'\+8801[3456789][0-9]{8}'
phone = "+8801736737699"

regnorx = r'[12][09][019][0-9]{7}'
regno = "2015331061"

matchObj = re.match(regnorx, regno, re.M|re.I)

if matchObj:
   print ("matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")
