import os
import time
import srcs.color as c
from tkinter import *
from PIL import ImageTk, Image
import numpy as np

class Photos(object):
    def __init__(self, photos, lab_photos, trash='trash/', auto_next=False, width=800, height=600):
        self.photos_dir = photos
        self.lab_photos_dir = lab_photos
        self.trash_dir = trash
        self.photo_act = 0
        self.fen = {
            'fen' : None,
            'lab_photo' : None,
            'photo' : None,
            'lab_info' : None,
            'info_top' : None
        }
        self.width = width
        self.height = height
        self.width_img = self.width
        self.height_img = self.height - 50
        self.auto_next = auto_next
        self.numjmp = ''


    def load(self):
        self.photos = os.listdir(self.photos_dir)
        self.photos_inf = [{'del' : False, 'label' : np.array([0 for i in range(26)]), 'view' : False} for i in range(len(self.photos))]
        self.photo_act = 0
        self.photos_inf[self.photo_act]['view'] = True


    def init_win(self, width=0, height=0):
        self.width = width if width != 0 else self.width
        self.width_img = width if width != 0 else self.width_img
        self.height_img = height - 50 if height != 0 else self.height_img
        self.fen['fen'] = Tk()
        self.fen['fen'].title('lab_photo')
        self.print_win()
        self.init_key()
        self.fen['fen'].mainloop()


    def init_key(self):
        self.fen['fen'].bind("<Escape>", self.quit_win)
        self.fen['fen'].bind("<BackSpace>", self.del_label)
        self.fen['fen'].bind("<Return>", self.event_enter)
        self.fen['fen'].bind("<Control-Key-s>", self.save)
        self.fen['fen'].bind("<Right>", self.next_photo)
        self.fen['fen'].bind("<Left>", self.last_photo)
        self.fen['fen'].bind("<Up>", self.del_photo)
        self.fen['fen'].bind("<KeyPress>", self.event_win)


    def save(self, event):
        print('save\n{')
        for i in range(len(self.photos)):
            if self.photos_inf[i]['del'] == True:
                print(c.RED + '\tDELETE -> ' + c.EOC + self.photos[i])
                os.rename(self.photos_dir + self.photos[i], self.trash_dir + self.photos[i])
            elif self.photos_inf[i]['view'] == True and (len(self.photos_inf) - 1 == i or self.photos_inf[i + 1]['view'] == True or sum(self.photos_inf[i]['label']) > 0):
                str_label = ''
                for j in range(len(self.photos_inf[i]['label'])):
                    if self.photos_inf[i]['label'][j] == 1:
                        str_label += chr(ord('a') + j)
                str_label = '.'.join(self.photos[i].split('.')[:-1]) + '_' + str_label + '.' + self.photos[i].split('.')[-1]
                print(c.GREEN + '\tMOVE -> ' + c.EOC + str_label)
                os.rename(self.photos_dir + self.photos[i], self.lab_photos_dir + str_label)
        print('}')
        self.load()
        self.print_win()


    def quit_win(self, event):
        self.save(None)
        self.fen['fen'].destroy()
        self.fen['fen'].quit()


    def del_label(self, event):
        if self.numjmp != '':
            self.numjmp = self.numjmp[:-1]
        else:
            self.photos_inf[self.photo_act]['label'] = [0 for i in range(26)]
        self.print_win()


    def event_enter(self, event):
        if self.numjmp != '':
            if self.numjmp[0] in ('+', '-'):
                if len(self.numjmp) > 1:
                    self.photo_act += int(self.numjmp)
                    if self.photo_act < 0:
                        self.photo_act == 0
                    self.photo_act %= len(self.photos)
            else:
                self.photo_act = int(self.numjmp) % len(self.photos)
            self.numjmp = ''
            self.print_win()


    def event_win(self, event):
        if event.char.isalpha() and ord(event.char) >= ord('a') and ord(event.char) <= ord('z'):
            if self.photos_inf[self.photo_act]['label'][ord(event.char) - ord('a')] == 1:
                self.photos_inf[self.photo_act]['label'][ord(event.char) - ord('a')] = 0
            else:
                self.photos_inf[self.photo_act]['label'][ord(event.char) - ord('a')] = 1
        elif event.char.isnumeric() or event.char == '-' or event.char == '+':
            if event.char == '-' or event.char == '+':
                if len(self.numjmp) == 0 or (len(self.numjmp) > 0 and not self.numjmp[0] in ('+', '-')):
                    self.numjmp = event.char + self.numjmp
                else:
                    self.numjmp = self.numjmp[1:]
            else:
                self.numjmp += event.char
        self.print_win()


    def del_photo(self, event):
        if self.photos_inf[self.photo_act]['del'] == True:
            self.photos_inf[self.photo_act]['del'] = False
        else:
            self.photos_inf[self.photo_act]['del'] = True
        if self.auto_next == True:
            self.next_photo(None)
        else:
            self.print_win()


    def last_photo(self, event):
        self.photo_act -= 1
        if self.photo_act < 0:
            self.photo_act = len(self.photos) - 1
        self.print_win()


    def next_photo(self, event):
        self.photo_act += 1
        if self.photo_act >= len(self.photos):
            self.photo_act = 0
        self.photos_inf[self.photo_act]['view'] = True
        self.print_win()


    def print_win(self):
        if self.fen['lab_photo'] != None:
            self.fen['lab_photo'].destroy()
        if self.fen['lab_info'] != None:
            self.fen['lab_info'].destroy()
        if self.fen['info_top'] != None:
            self.fen['info_top'].destroy()

        self.fen['info_top'] = Label(self.fen['fen'], width=32,  height=2, font=("Courier", 35))
        self.fen['info_top'].configure(bg='white')
        str_label = ''
        for i in range(len(self.photos_inf[self.photo_act]['label'])):
            if self.photos_inf[self.photo_act]['label'][i] == 1:
                str_label += chr(ord('a') + i)
        str_label = '.'.join(self.photos[i].split('.')[:-1]) + '_' + str_label + '.' + self.photos[i].split('.')[-1] + ' ' + str(self.photo_act) + '/' + str(len(self.photos))
        self.fen['info_top']['text'] = str_label
        self.fen['info_top'].pack(fill=X)

        image = Image.open(self.photos_dir + self.photos[self.photo_act])
        image = image.resize((self.width_img, self.height_img), Image.ANTIALIAS)
        self.fen['photo'] = ImageTk.PhotoImage(image)
        self.fen['lab_photo'] = Label(self.fen['fen'], image=self.fen['photo'])
        self.fen['lab_photo'].pack(fill=X)

        self.fen['lab_info'] = Label(self.fen['fen'], width=32,  height=2, font=("Courier", 40))
        if self.photos_inf[self.photo_act]['del'] == True:
            self.fen['lab_info'].configure(bg='red')
        else:
            self.fen['lab_info'].configure(bg='white')
        str_label = ''
        for i in range(len(self.photos_inf[self.photo_act]['label'])):
            if self.photos_inf[self.photo_act]['label'][i] == 1:
                str_label += chr(ord('a') + i)
        if self.numjmp != '':
            str_label += '\t' + self.numjmp
        self.fen['lab_info']['text'] = str_label
        self.fen['lab_info'].pack(fill=X)
