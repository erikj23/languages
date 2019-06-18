
class restaurant():
    def __init__(self, name:str, cuisine:str) -> None:
        self.name = name.title()
        self.cuisine = cuisine.title()

    def describe_restaurant(self) -> None:
        print("{} sells {} food.".format(self.name, self.cuisine))

    def open_restaurant(self) -> None:
        print("{} is now open!".format(self.name))

if __name__ == "__main__":
    yi = restaurant("yibiki's", "malaysian")
    yi.open_restaurant()
    yi.describe_restaurant()
