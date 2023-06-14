class Controller:
    def __init__(self, repo):
        self.repo = repo
        self.score = self.__calculate_score()


    def move(self, word1, index1, word2, index2):
        """
        swap word1 index1 - word2 index2
        :param word1: int, index of the first word
        :param index1: int, index of the character of the first word
        :param word2: int, index of the second word
        :param index2: int, index of the character of the second word
        """
        self.repo.move(word1, index1, word2, index2)


    def __calculate_score(self):
        """

        :return: the initial score of the game
        """
        score = 0
        l = self.repo.scrambled
        for word in l:
            score = score + len(word)
        return score


    def decrement_score(self):
        """
        decrements self.score with 1
        """
        self.score -= 1






