
class Car():

    """A simple attempt to represent a car."""

    def __init__(self, make: str, model: str, year: int) -> None:
        self.make = make.title()
        self.model = model.title()
        self.year = year
        self.odometer_reading = 0

    def get_description(self) -> None:
        long_name = "{} {} {}".format(str(self.year), self.make, self.model)
        return long_name
    
    def read_odometer(self) -> None:
        print("This car has {} miles on it".format(str(self.odometer_reading)))
    
    def update_odometer(self, milage: int) -> None:
        if milage >= self.odometer_reading:
            self.odometer_reading = milage
        else:
            print("error in {}: invalid milage".format(update_odometer.__name__))
    
    def increment_odometer(self, miles: int) -> None:
        if miles >= 0:
            self.odometer_reading += miles
        else:
            print("error in {}: invalid miles".format(increment_odometer.__name__))

class electric_car(car):
    
    def __init__(self, make:str, model:str, year:int)->None:
        super.__init__(make, model, year)
        
        
class combustion_car(car):
    def __init__(self, make:str, model:str, year:int)->None:
        super.__init__(make, model, year)


