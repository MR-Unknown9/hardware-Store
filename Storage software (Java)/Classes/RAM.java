package Classes;
public class RAM extends Hardware {
    int capacity;
    int speed;

    RAM(String name, String manufacturer, double price, int capacity, int speed) {
        super(name, manufacturer, price);
        this.capacity = capacity;
        this.speed = speed;
    }
}
