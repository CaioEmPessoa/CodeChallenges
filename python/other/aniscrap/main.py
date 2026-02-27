from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.firefox.options import Options
from webdriver_manager.firefox import GeckoDriverManager

import os
import json
import requests
from datetime import datetime
from dotenv import load_dotenv
from bs4 import BeautifulSoup

import urllib.request

load_dotenv()

ANIME_EPISODE_URL = os.getenv("ANIME_EPISODE_URL")

if ANIME_EPISODE_URL=="":
    input("PLEASE ADD YOUR INFO INTO .ENV FILE.")
    exit()

options = Options()

# don't open the broser
# options.add_argument("--headless")
# options.add_argument("--silent")
# options.add_argument("--log-level=3")

# don't kills chrome when code ends
#options.add_experimental_option("detach", True)

#options.add_experimental_option('excludeSwitches', ['enable-logging'])

# Donwload driver (If needed) and starts it
driver = webdriver.Firefox(service=Service(GeckoDriverManager().install()), options=options)

driver.install_addon("/home/caio/Projetos/animesscrapper/ublockorigin.xpi", temporary=True)

driver.implicitly_wait(10)

def search():
    driver.get(ANIME_EPISODE_URL)

    buscando = True
    while (buscando):
        current_episode = driver.current_url
        try:
            nextVidBtn = driver.find_element(By.CLASS_NAME, "proximoLink")
        except:
            buscando=False
            break


        # troca o player
        player2btn = driver.find_element(By.CSS_SELECTOR, '[data-tab="#player2"]')
        player2btn.click()

        # encontra a div com o segundo e o iframe principal do site
        player2div = driver.find_element(By.ID, "player2")
        player2frame = player2div.find_element(By.CSS_SELECTOR, "iframe")

        driver.switch_to.frame(player2frame)

        html = driver.page_source


        # procura e abre o iframe do segundo player na mesma aba
        soup = BeautifulSoup(html, 'html.parser')
        iframe = soup.find("iframe", {"class":"metaframe rptss no-lazy"})

        iframeSrcs = iframe.get("src")

        driver.get(iframeSrcs)

        # gera o iframe da google no click
        vidDiv = driver.find_element(By.CLASS_NAME, "ppVepb")
        vidDiv.click()

        # troca pro player da google
        googleFrame = driver.find_element(By.ID, "widget2")
        driver.switch_to.frame(googleFrame)

        ## encontra o url e baixa o video
        vidurl = driver.find_element(By.CSS_SELECTOR, "video").get_attribute("src")

        # Get user-agent from driver
        user_agent = driver.execute_script("return navigator.userAgent;")

        # Set up headers
        headers = {
            'User-Agent': user_agent,
            'Referer': driver.current_url,  # Important for video streams
            'Accept': 'video/webm,video/ogg,video/*;q=0.9,application/ogg;q=0.7,*/*;q=0.8',
            'Accept-Language': 'en-US,en;q=0.5',
            'Connection': 'keep-alive',
        }

        # Download the video
        response = requests.get(vidurl, headers=headers, stream=True)

        if response.status_code == 200:
            print("Video encontrado!")
            chunkSize = 2 * 1024 * 1024
            responseIt = response.iter_content(chunk_size=chunkSize)
            dwnldIndex = 0;
            dwnldSize = int(response.headers.get('content-length', 0))

            with open('videoname.mp4', 'wb') as f:
                for chunk in responseIt:
                    print(f"Download: {dwnldIndex/1000000:2f}mb/{dwnldSize/1000000:2f}mb")
                    f.write(chunk)
                    dwnldIndex+=chunkSize


        # vai pro proximo
        driver.get(current_episode)
        nextVidBtn.click()

    driver.close()
    print("todos episodios foram baixados!")

try:
    search()
except Exception as err:
    # driver.close()
    raise err
