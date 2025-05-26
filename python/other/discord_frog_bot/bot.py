from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager

from os import getcwd, path

from random import choice, randint
from datetime import datetime


with open("date.txt", "r") as x:
    current_date = datetime.now().strftime("%d/%m")

    if current_date == x.read():
        print("duas vez no mesmo dia nao ne amigao kk eee laia viu")
        exit()

with open("date.txt", "w") as x:
    x.write(current_date)

def GenerateGame():
    with open("numb.txt", "r") as x:
        numb = int(x.read())

    SIZES = [3, 4, 5]

    rand_size = choice(SIZES)

    itens = [["||:hatching_chick:||" for i in range(rand_size)] for i in range(rand_size)]

    itens[randint(0, rand_size-1)][randint(0, rand_size-1)] = "||:frog:||"

    final_string = f"Encontre o Sapo #{numb}!Muda todo dia!\n"

    for i in itens:
        final_string += "".join(i) + "\n"

    with open("numb.txt", "w") as x:
        x.write(str(numb+1))

    return final_string

# Valores Iniciais
WEBSITE = r"https://www.discord.app/"

# Add the temp files to the chrome
options = Options()

# Saves chrome info into local folder.
options.add_argument(f"user-data-dir={getcwd()}/User_Data")

if path.exists(f"{getcwd()}/User_Data"):
    print("")
    # Don't open the chrome window

    # this options don't work :(
    # options.add_argument("--headless")
    # options.add_argument("--silent")
    # options.add_argument("--log-level=3")
else:
    # The code don't close on end
    options.add_experimental_option("detach", True)

# Donwload driver (If needed) and starts it
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

driver.implicitly_wait(30)

#Access website
driver.get(WEBSITE)

driver.find_element(By.CSS_SELECTOR, "[aria-label='User Settings']").click()
driver.find_element(By.CSS_SELECTOR, "[aria-label='Profiles']").click()


bio = driver.find_element(By.CSS_SELECTOR, "[role='textbox']")

bio.click()
bio.click()

bio.send_keys(Keys.CONTROL + "a")

## ACTUALLY SENDING THE BIO
bio.send_keys(GenerateGame())

driver.find_element(By.XPATH, "//button[contains(., 'Save Changes')]").click()

print("Bio mudada!")