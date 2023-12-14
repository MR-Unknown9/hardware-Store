package Classes;
<<<<<<< HEAD
public class RAM extends Hardware {
=======

class RAM extends Hardware {
>>>>>>> 08e5e0eb28ab5a14785afa236b4444d0d49cfaa3
    int capacity;
    int speed;

    RAM(String name, String manufacturer, double price, int capacity, int speed) {
        super(name, manufacturer, price);
        this.capacity = capacity;
        this.speed = speed;
    }
}
