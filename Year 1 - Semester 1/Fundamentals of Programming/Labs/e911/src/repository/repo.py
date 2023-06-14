from random import randint, shuffle
from copy import copy
class Repository:
    def __init__(self, file_name):
        """
        initialiaze an object of type repo
        :param file_name: string, a given file
        """
        self.file_name = file_name
        self.original_sentence = self.__random_sentence() # the picked sentence
        self.words_list = self.original_sentence.split(" ")
        self.scrambled = self.scrambled_sentece()



    def __random_sentence(self):
        """
        choose a random sentence from a given file
        """
        self.__scramble_list = []
        with open(self.file_name, "r") as f: # read the sentences of the file
            self.__scramble_list = f.readlines()
        choice = randint(0, len(self.__scramble_list) - 1)  # choose a random sentence
        return self.__scramble_list[choice]  # the picked sentence


    def scrambled_sentece(self):
        """
        scramble the chosen sentence
        """
        self.shuffled_sentence = []
        self.words_list = self.original_sentence.split(" ")
        word = self.words_list[len(self.words_list)-1]
        new_w = ""
        for i in range(len(word)-1):
            new_w = new_w + word[i]

        self.shuffled_sentence = []

        for index, word in enumerate(self.words_list):
            indices_list = [i for i in range(1, len(word) - 1)]
            shuffle(indices_list)
            new_word = ""
            if len(word) >= 1:
                new_word = new_word + word[0]
            for i in indices_list:
                new_word = new_word + word[i]

            if len(word) >= 2:
                new_word = new_word + word[len(word)-1]
            self.shuffled_sentence.append(new_word)
        return self.shuffled_sentence


    def move(self, word1, index1, word2, index2):
        """
        swap word1 index1 - word2 index2
        :param word1: int, index of the first word
        :param index1: int, index of the character of the first word
        :param word2: int, index of the second word
        :param index2: int, index of the character of the second word
        """
        if len(self.scrambled) <= word1 or len(self.scrambled) <= word2:
            raise Exception("Word index out of range!")
        w1 = self.scrambled[word1]
        w2 = self.scrambled[word2]
        if index1 <= 0 or index1 >= len(w1)-1:
            raise Exception("Index out of range!")
        if index2 <= 0  or index2 >= len(w2)-1:
            raise Exception("Index out of range!")

        if word1 != word2:
            ch1 = copy(w1[index1])
            ch2 = copy(w2[index2])
            new_w1 = ""
            new_w2 = ""
            for i in range(0, len(w1)):
                if i != index1:
                    new_w1 = new_w1 + w1[i]
                else:
                    new_w1 = new_w1 + ch2

            for i in range(0, len(w2)):
                if i != index2:
                    new_w2 = new_w2 + w2[i]
                else:
                    new_w2 = new_w2 + ch1

            self.scrambled[word1], self.scrambled[word2] = new_w1, new_w2
        else:
            ch1 = copy(w1[index1])
            ch2 = copy(w2[index2])
            new_w = ""
            for i in range(0, len(w1)):
                if i == index1:
                    new_w = new_w + ch2
                elif i == index2:
                    new_w = new_w + ch1
                else:
                    new_w = new_w + w1[i]
            self.scrambled[word1] = new_w

