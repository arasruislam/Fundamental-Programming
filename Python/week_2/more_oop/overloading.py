class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

    def eat(self):
        print("Vat mangso polau korma")

    def exercise(self):
        raise NotImplementedError


class Cricketer(Person):
    def __init__(self, name, age, height, weight, team) -> None:
        self.team = team
        super().__init__(name, age, height, weight)

    def eat(self):
        print("Vegetable")

    def exercise(self):
        print("Hey gym")
    
    # overloading
    def __add__(self, other):
        return self.age + other.age


sakib = Cricketer("Sakib", 38, 68, 98, "BD")
musi = Cricketer("Musi", 33, 62, 88, "BD")
# sakib.eat()
# sakib.exercise()

print(sakib + musi)