'''

import nltk
from nltk.corpus import words

nltk.download('words')

english_words_lower = sorted(word.lower() for word in words.words())

with open("corpus.txt" , "w") as file:
    for word in english_words_lower: file.write(word + "\n")

'''
