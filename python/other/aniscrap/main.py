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
        try:
            nextVidBtn = driver.find_element(By.CLASS_NAME, "proximoLink")
        except:
            buscando=False
            break

        # troca o player
        player2btn = driver.find_element(By.CSS_SELECTOR, '[data-tab="#player2"]')
        player2btn.click()

        # troca view pro iframe do player

        # TEM DOIS IFRAMES
        # O DO PROPORIO ANIMESDIGITAL E O DO SITE, QUE MUDA. ELES NAO SAO IDENTIFICAVEIS A NAO SER PELO SRC.
        # segue os links:
        '''
            https://animesdigital.org/aHR0cHM6Ly9idWxib3ZhLmJsb2dzcG90LmNvbS8yMDIzLzAyL3N0ZXZlbi11bmktZHUuaHRtbA==/106/bg.mp4?p=2&q=U3RldmVuIFVuaXZlcnNvIER1YmxhZG8gRGVzZW5obyAxMDc=&nocache1770471573

            https://www.blogger.com/video.g?token=AD6v5dwG05Mf84MVXKEWBhkm226BxUdCH5tCLl4uDDHFivX66vc_0b9iaoXbgC3PcvQbY3szXDezxJOK-I5Lp7VqyhjgjPF7UCXRlljr7fQt0tYQHOc4jO0L0NgIxBtpWZ5z0ID-aZI
        '''

        iframe = driver.find_element(By.CSS_SELECTOR, "iframe.metaframe.rptss.no-lazy")
        iframeSrc = iframe.get_attribute('src')

        # driver.switch_to.frame(iframe);

        # driver.get(iframeSrc);

        # play
        vidPlayer = driver.find_element(By.CLASS_NAME, "ppVepb")
        vidPlayer.click()

        # troca qualidade
        configBtn = driver.find_element(By.CSS_SELECTOR, '[data-tooltip-target-id="ytp-settings-button"]')
        configBtn.click()

        qualityMenu = driver.find_elements_by_xpath("//*[contains(text(), 'Quality')]")
        qualityMenu.click()
        qualityOptn = driver.find_elements_by_xpath("//*[contains(text(), '720p')]")
        qualityOptn.click()

        qualityConfig = driver.find_element(By.CLASS_NAME, "ytp-menuitem-label")

        ## baixar o video


        # vai pro proximo
        nextVidBtn.click()

    driver.close()
    print("todos episodios foram baixados!")

try:
    search()
except Exception as err:
    # driver.close()
    raise err
