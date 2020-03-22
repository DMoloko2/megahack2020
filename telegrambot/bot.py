import telebot
import time

bot = telebot.TeleBot('1130520112:AAGwfRlrJVScdjNc3A5MnmqdmnJs5aeqaUA')
#keyboard1 = telebot.types.ReplyKeyboardMarkup()
#keyboard1.row('Привет', 'Пока')
@bot.message_handler(commands=['start'])
def start_message(message):
    sti = open('sticker.webp','rb')
    bot.send_sticker(message.chat.id, sti)
    bot.send_message(message.chat.id, 'Добро пожаловать, при критических изменениях вам придет сообщение')
    while True:
        try:
            file = open('ip.txt','r')
        except:
            time.sleep(1)
        else:
            error_message = file.read(10)
            tags = file.read(2)
            if error_message == "b'pressure":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель давления(P) на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'roomTemp":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель температуры помещения(T) на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'humidity":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель влажности  на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'zoneTemp":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель температуры рабочей зоны(T_zone) на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'pn_level":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель уровня pH на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'massives":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель массы(М) на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'flowRate":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель расхода жидкости на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()
            elif error_message == "b'gas_of_C":
                bot.send_message(message.chat.id, 'Внимание! Превышен предельно допустимый показатель уровня СО2 на датчике № ' + tags + '! Для получения более подробной информации зайдите в веб-клиент')
                file.close()
                file = open('ip.txt','w')
                file.close()

bot.polling()
