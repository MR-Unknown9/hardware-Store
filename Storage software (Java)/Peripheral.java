
public class Peripheral extends Hardware {
    String connection;
    String type;

    Peripheral(String name, String manufacturer, double price, String connection, String type) {
        super(name, manufacturer, price);
        this.connection = connection;
        this.type = type;
    }
}