package Classes;

class GPU extends Hardware {
    int memory;

    GPU(String name, String manufacturer, double price, int memory) {
        super(name, manufacturer, price);
        this.memory = memory;
    }
}
