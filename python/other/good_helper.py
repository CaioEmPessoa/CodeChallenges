from datetime import datetime

horas = int(datetime.now().strftime("%H"))

if horas > 6 and horas < 12:
    print("Bom dia!")
elif horas < 18:
    print("Boa tarde!")
elif horas < 24:
    print("Boa noite!")
else:
    print("Boa madrugada!")
