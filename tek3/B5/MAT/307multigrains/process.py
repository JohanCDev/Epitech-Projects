#!/usr/bin/env python3.10

VALUE_EXCEEDED = 99999999999999

GRAINS_INFO = {
    'Oat': [1, 1, 2, 0],
    'Wheat': [0, 2, 1, 0],
    'Corn': [1, 0, 0, 3],
    'Barley': [0, 1, 1, 1],
    'Soy': [2, 0, 0, 2]
}


class Multigrains:
    def __init__(self, argv):
        self.MAX_X = 10
        self.MAX_Y = 5
        self.f1 = int(argv[1])
        self.f2 = int(argv[2])
        self.f3 = int(argv[3])
        self.f4 = int(argv[4])
        self.oatmeal = int(argv[5])
        self.wheat = int(argv[6])
        self.corn = int(argv[7])
        self.barley = int(argv[8])
        self.soy = int(argv[9])

        self.calcMatrix = []
        self.calcMatrix.append([1, 0, 1, 0, 2, 1, 0, 0, 0, self.f1])
        self.calcMatrix.append([1, 2, 0, 1, 0, 0, 1, 0, 0, self.f2])
        self.calcMatrix.append([2, 1, 0, 1, 0, 0, 0, 1, 0, self.f3])
        self.calcMatrix.append([0, 0, 3, 1, 2, 0, 0, 0, 1, self.f4])
        self.calcMatrix.append(
            [-self.oatmeal, -self.wheat, -self.corn, -self.barley, -self.soy, 0, 0, 0, 0, 0])

        self.prices = [self.oatmeal, self.wheat,
                       self.corn, self.barley, self.soy]
        self.prod = [0, 0, 0, 0, 0]
        self.total_cost = 0

    def define_pivot(self):
        all_prices = self.calcMatrix[-1][:5]
        min_price = min(all_prices)

        y = -1
        x = all_prices.index(min_price)
        min_price = VALUE_EXCEEDED

        for i in range(self.MAX_Y):
            if self.calcMatrix[i][self.MAX_X - 1]:
                if self.calcMatrix[i][x] > 0 and (min_price > (self.calcMatrix[i][self.MAX_X - 1] / self.calcMatrix[i][x]) and (self.calcMatrix[i][self.MAX_X - 1] / self.calcMatrix[i][x]) > 0):
                    min_price = self.calcMatrix[i][self.MAX_X -
                                                   1] / self.calcMatrix[i][x]
                    y = i
            elif min_price > self.calcMatrix[i][x] and self.calcMatrix[i][x] > 0:
                min_price = self.calcMatrix[i][self.MAX_X -
                                               1] / self.calcMatrix[i][x]
                y = i

        return x, y

    def compute_pivot(self, x, y):
        value = self.calcMatrix[y][x]
        for i in range(len(self.calcMatrix[y])):
            self.calcMatrix[y][i] /= value

        for i in range(5):
            if i != y:
                k = self.calcMatrix[i][x]
                for j in range(10):
                    self.calcMatrix[i][j] -= (k * self.calcMatrix[y][j])

    def compute_prices_for_resources(self, res):
        for i in range(self.MAX_Y - 1):
            if res[i] != -1:
                if self.calcMatrix[i][-1]:
                    self.total_cost += self.calcMatrix[i][-1] * \
                        self.prices[res[i]]
                self.prod[res[i]] = self.calcMatrix[i][-1]

    def run(self):

        res = [-1, -1, -1, -1]

        for _ in range(self.MAX_Y):
            x, y = self.define_pivot()
            if x < 0 or y < 0:
                break
            self.compute_pivot(x, y)
            res[y] = x

        self.compute_prices_for_resources(res)

    def print_res(self):
        unit_oat = self.prod[0]
        unit_wheat = self.prod[1]
        unit_corn = self.prod[2]
        unit_barley = self.prod[3]
        unit_soy = self.prod[4]

        print(
            f'Resources: {self.f1} F1, {self.f2} F2, {self.f3} F3, {self.f4} F4\n')

        if unit_oat != 0:
            print("Oat: %.2f " % (unit_oat), end='')
        else:
            print("Oat: 0 ", end='')
        print(f'units at ${self.oatmeal}/unit')

        if unit_wheat != 0:
            print("Wheat: %.2f " % (unit_wheat), end='')
        else:
            print("Wheat: 0 ", end='')
        print(f'units at ${self.wheat}/unit')

        if unit_corn != 0:
            print("Corn: %.2f " % (unit_corn), end='')
        else:
            print("Corn: 0 ", end='')
        print(f'units at ${self.corn}/unit')

        if unit_barley != 0:
            print("Barley: %.2f " % (unit_barley), end='')
        else:
            print("Barley: 0 ", end='')
        print(f'units at ${self.barley}/unit')

        if unit_soy != 0:
            print("Soy: %.2f " % (unit_soy), end='')
        else:
            print("Soy: 0 ", end='')
        print(f'units at ${self.soy}/unit\n')

        print("Total production value: $%.2f" % (self.total_cost))


def process(argc, argv):

    mathExecute = Multigrains(argv)
    mathExecute.run()
    mathExecute.print_res()
    return 0
