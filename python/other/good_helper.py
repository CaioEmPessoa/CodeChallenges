from datetime import datetime

horas = int(datetime.now().strftime("%H"))

if horas > 4 and horas < 12:
    print("Bom dia!")
elif horas < 18:
    print("Boa tarde!")
else:
    print("Boa noite!")