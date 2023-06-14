from copy import deepcopy
class IteratorClass:
    def __init__(self, colection):
        self.__index = 0
        self.__colection = colection


    def __next__(self):# returns a tuple which contains the current index and its content
        if self.__index == len(self.__colection.data):
            raise StopIteration()
        result = self.__colection.data[self.__index]
        self.__index += 1
        return result


class Collection:
    def __init__(self, data):
        self.__data = []
        for el in data:
            self.__data.append(deepcopy(el))


    @property
    def data(self):
        return self.__data


    @data.setter
    def data(self, index, value):
        self.__data[index] = value


    def __iter__(self):
        return IteratorClass(self)


    def __iter__(self):
        return IteratorClass(self)


    def __len__(self):
        return len(self.__data)


    def __setitem__(self, key, value):
        if 0 <= key <= len(self.__data):
            self.__data[key] = value
        else:
            raise Exception("Not a valid position!")


    def __getitem__(self, item):
        if 0 <= item <= len(self.__data):
            return self.__data[item]
        else:
            raise Exception("Not a valid position!")


    def __delitem__(self, item):
        for el in self.__data:
            if el == item:
                self.__data.remove(el)
                return


    def append(self, item):
        self.__data.append(item)


    def remove(self, item):
        self.__data.remove(item)


class Algorithms:
    def __init__(self, data):
        self.__list = Collection(data)


    def shell_sort(self, function):
        gap = len(self.__list.data) // 2
        while gap > 0:
            i = 0
            j = gap
           # check the list in from left to right till the last possible index of j
            while j < len(self.__list.data):
                if function(self.__list.data[i], self.__list.data[j]):
                    self.__list.data[i], self.__list.data[j] = self.__list.data[j], self.__list.data[i]
                i += 1
                j += 1

            # now we check from the i-th index to the left and swap the value which are not in the right order
            k = i
            while k > gap - 1:
                if function(self.__list.data[k-gap], self.__list.data[k]):
                    self.__list.data[k - gap], self.__list.data[k] = self.__list.data[k], self.__list.data[k-gap]
                k -= 1

            gap //= 2

        return self.__list.data


    def filter(self, function):
        result = []
        for element in self.__list:
            if function(element) == False:
                continue
            result.append(element)
        return result