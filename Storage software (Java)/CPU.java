


public class CPU extends Hardware {
    int cores;
    double frequency;

    CPU(String name, String manufacturer, double price, int cores, double frequency) {
        super(name, manufacturer, price);
        this.cores = cores;
        this.frequency = frequency;
    }
}