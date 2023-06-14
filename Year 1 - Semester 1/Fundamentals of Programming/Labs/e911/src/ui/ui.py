from src.repository.repo import Repository
from src.controller.controller import Controller

class Ui:
    def __init__(self, repo):
        self.controller = Controller(repo)


    def swap(self):
        try:
            command = input("command = ")
            tokens = command.split(" ")
            if len(tokens) < 6:
                raise Exception("Invalid command! The must have 5 tokens")
            cmd = tokens[0].casefold()
            word1 = int(tokens[1])
            index1 = int(tokens[2])
            seperator = tokens[3]
            word2 = int(tokens[4])
            index2 = int(tokens[5])
            self.controller.move(word1, index1, word2, index2)
            self.decrement_score_ui()
        except Exception as e:
            print(e)


    def decrement_score_ui(self):
        self.controller.decrement_score()


    def game_state(self):
        original_sentence = self.controller.repo.words_list
        altered_sentence = self.controller.repo.scrambled
        if original_sentence == altered_sentence:
            print("Victory!")
            exit()
        if self.controller.score == 0:
            print("Game Over!")
            exit()


    def print_sentence(self):
        l = self.controller.repo.scrambled
        print(self.controller.score)
        res = ""
        for index, word in enumerate(l):
            if index == len(l) - 1:
                res = res + word
            else:
                res = res + word + " "
        print(res)


    def play(self):
        while True:
            self.game_state()
            self.print_sentence()
            self.swap()

p = Ui(Repository("file.txt"))
p.play()



