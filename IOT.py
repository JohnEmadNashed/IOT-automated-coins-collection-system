from firebase import firebase

firebase = firebase.FirebaseApplication('https://iotprojec.firebaseio.com/')
result = firebase.get('/inputDataFromAndroid',None)
print (result)