
public class Case extends Hardware {
    String size;
    String color;

    Case(String name, String manufacturer, double price, String size, String color) {
        super(name, manufacturer, price);
        this.size = size;
        this.color = color;
    }
}
