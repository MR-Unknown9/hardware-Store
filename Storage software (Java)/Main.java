import java.util.*;

class Hardware {
    String name;
    String manufacturer;
    double price;

    Hardware(String name, String manufacturer, double price) {
        this.name = name;
        this.manufacturer = manufacturer;
        this.price = price;
    }
}

class CPU extends Hardware {
    int cores;
    double frequency;

    CPU(String name, String manufacturer, double price, int cores, double frequency) {
        super(name, manufacturer, price);
        this.cores = cores;
        this.frequency = frequency;
    }
}

class GPU extends Hardware {
    int memory;

    GPU(String name, String manufacturer, double price, int memory) {
        super(name, manufacturer, price);
        this.memory = memory;
    }
}

class RAM extends Hardware {
    int capacity;
    int speed;

    RAM(String name, String manufacturer, double price, int capacity, int speed) {
        super(name, manufacturer, price);
        this.capacity = capacity;
        this.speed = speed;
    }
}

class StorageUnit extends Hardware {
    int capacity;
    String type;

    StorageUnit(String name, String manufacturer, double price, int capacity, String type) {
        super(name, manufacturer, price);
        this.capacity = capacity;
        this.type = type;
    }
}

class Motherboard extends Hardware {
    String model;

    Motherboard(String name, String manufacturer, double price, String model) {
        super(name, manufacturer, price);
        this.model = model;
    }
}

class PowerSupply extends Hardware {
    int wattage;
    String efficiency;

    PowerSupply(String name, String manufacturer, double price, int wattage, String efficiency) {
        super(name, manufacturer, price);
        this.wattage = wattage;
        this.efficiency = efficiency;
    }
}

class CoolingSystem extends Hardware {
    String type;

    CoolingSystem(String name, String manufacturer, double price, String type) {
        super(name, manufacturer, price);
        this.type = type;
    }
}

class Case extends Hardware {
    String size;
    String color;

    Case(String name, String manufacturer, double price, String size, String color) {
        super(name, manufacturer, price);
        this.size = size;
        this.color = color;
    }
}

class Peripheral extends Hardware {
    String type;
    String connection;

    Peripheral(String name, String manufacturer, double price, String type, String connection) {
        super(name, manufacturer, price);
        this.type = type;
        this.connection = connection;
    }
}

class StorageSystem {
    List<Hardware> hardwareList;

    StorageSystem() {
        this.hardwareList = new ArrayList<>();
    }

    void add(Hardware hardware) {
        this.hardwareList.add(hardware);
    }

    void remove(Hardware hardware) {
        this.hardwareList.remove(hardware);
    }

    Hardware search(String name) {
        for (Hardware hardware : this.hardwareList) {
            if (hardware.name.equals(name)) {
                return hardware;
            }
        }
        return null;
    }

    void display() {
    for (Hardware hardware : this.hardwareList) {
        String type = "Unknown";
        if (hardware instanceof CPU) {
            type = "CPU";
            CPU cpu = (CPU) hardware;
            System.out.println("NAME: " + cpu.name + ", TYPE: " + type + ", PRICE: " + cpu.price + ", MANUFACTURER: " + cpu.manufacturer + ", CORES: " + cpu.cores + ", FREQUENCY: " + cpu.frequency);
        } else if (hardware instanceof GPU) {
            type = "GPU";
            GPU gpu = (GPU) hardware;
            System.out.println("NAME: " + gpu.name + ", TYPE: " + type + ", PRICE: " + gpu.price + ", MANUFACTURER: " + gpu.manufacturer + ", MEMORY: " + gpu.memory);
        } else if (hardware instanceof RAM) {
            type = "RAM";
            RAM ram = (RAM) hardware;
            System.out.println("NAME: " + ram.name + ", TYPE: " + type + ", PRICE: " + ram.price + ", MANUFACTURER: " + ram.manufacturer + ", CAPACITY: " + ram.capacity + ", SPEED: " + ram.speed);
        } else if (hardware instanceof StorageUnit) {
            type = "Storage Unit";
            StorageUnit storageUnit = (StorageUnit) hardware;
            System.out.println("NAME: " + storageUnit.name + ", TYPE: " + type + ", PRICE: " + storageUnit.price + ", MANUFACTURER: " + storageUnit.manufacturer + ", CAPACITY: " + storageUnit.capacity + ", TYPE: " + storageUnit.type);
        } else if (hardware instanceof Motherboard) {
            type = "Motherboard";
            Motherboard motherboard = (Motherboard) hardware;
            System.out.println("NAME: " + motherboard.name + ", TYPE: " + type + ", PRICE: " + motherboard.price + ", MANUFACTURER: " + motherboard.manufacturer + ", MODEL: " + motherboard.model);
        } else if (hardware instanceof PowerSupply) {
            type = "Power Supply";
            PowerSupply powerSupply = (PowerSupply) hardware;
            System.out.println("NAME: " + powerSupply.name + ", TYPE: " + type + ", PRICE: " + powerSupply.price + ", MANUFACTURER: " + powerSupply.manufacturer + ", WATTAGE: " + powerSupply.wattage + ", EFFICIENCY: " + powerSupply.efficiency);
        } else if (hardware instanceof CoolingSystem) {
            type = "Cooling System";
            CoolingSystem coolingSystem = (CoolingSystem) hardware;
            System.out.println("NAME: " + coolingSystem.name + ", TYPE: " + type + ", PRICE: " + coolingSystem.price + ", MANUFACTURER: " + coolingSystem.manufacturer + ", TYPE: " + coolingSystem.type);
        } else if (hardware instanceof Case) {
            type = "Case";
            Case caseHardware = (Case) hardware;
            System.out.println("NAME: " + caseHardware.name + ", TYPE: " + type + ", PRICE: " + caseHardware.price + ", MANUFACTURER: " + caseHardware.manufacturer + ", SIZE: " + caseHardware.size + ", COLOR: " + caseHardware.color);
        } else if (hardware instanceof Peripheral) {
            type = "Peripheral";
            Peripheral peripheral = (Peripheral) hardware;
            System.out.println("NAME: " + peripheral.name + ", TYPE: " + type + ", PRICE: " + peripheral.price + ", MANUFACTURER: " + peripheral.manufacturer + ", TYPE: " + peripheral.type + ", CONNECTION: " + peripheral.connection);
        }
    }
}


    int count() {
        return this.hardwareList.size();
    }
}

public class Main {
    public static void main(String[] args) {
        StorageSystem storageSystem = new StorageSystem();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Please choose an option:");
            System.out.println("1. Add hardware");
            System.out.println("2. Remove hardware");
            System.out.println("3. Search for hardware");
            System.out.println("4. Display all hardware");
            System.out.println("5. Count hardware");
            System.out.println("6. Exit");

            int option = scanner.nextInt();
            scanner.nextLine();

            switch (option) {
                case 1:
                    Hardware hardware = null;
                    while (hardware == null) {
                        System.out.println("Enter hardware type:");
                        String type = scanner.nextLine();
                        switch (type.toLowerCase()) {
                            case "cpu":
                                System.out.println("Enter number of cores:");
                                int cores = scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Enter frequency:");
                                double frequency = scanner.nextDouble();
                                scanner.nextLine();
                                hardware = new CPU("CPU", "Unknown", 0.0, cores, frequency);
                                break;
                            case "gpu":
                                System.out.println("Enter memory:");
                                int memory = scanner.nextInt();
                                scanner.nextLine();
                                hardware = new GPU("GPU", "Unknown", 0.0, memory);
                                break;
                            case "ram":
                                System.out.println("Enter capacity:");
                                int capacity = scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Enter speed:");
                                int speed = scanner.nextInt();
                                scanner.nextLine();
                                hardware = new RAM("RAM", "Unknown", 0.0, capacity, speed);
                                break;
                            case "storageunit":
                                System.out.println("Enter capacity:");
                                capacity = scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Enter type (SSD or HDD):");
                                String storageType = scanner.nextLine();
                                hardware = new StorageUnit("Storage Unit", "Unknown", 0.0, capacity, storageType);
                                break;
                            case "motherboard":
                                System.out.println("Enter model:");
                                String model = scanner.nextLine();
                                hardware = new Motherboard("Motherboard", "Unknown", 0.0, model);
                                break;
                            case "powersupply":
                                System.out.println("Enter wattage:");
                                int wattage = scanner.nextInt();
                                scanner.nextLine();
                                System.out.println("Enter efficiency:");
                                String efficiency = scanner.nextLine();
                                hardware = new PowerSupply("Power Supply", "Unknown", 0.0, wattage, efficiency);
                                break;
                            case "coolingsystem":
                                System.out.println("Enter type:");
                                String coolingType = scanner.nextLine();
                                hardware = new CoolingSystem("Cooling System", "Unknown", 0.0, coolingType);
                                break;
                            case "case":
                                System.out.println("Enter size:");
                                String size = scanner.nextLine();
                                System.out.println("Enter color:");
                                String color = scanner.nextLine();
                                hardware = new Case("Case", "Unknown", 0.0, size, color);
                                break;
                            case "peripheral":
                                System.out.println("Enter type:");
                                String peripheralType = scanner.nextLine();
                                System.out.println("Enter connection:");
                                String connection = scanner.nextLine();
                                hardware = new Peripheral("Peripheral", "Unknown", 0.0, peripheralType, connection);
                                break;
                            default:
                                System.out.println("Invalid hardware type. Please try again.");
                        }
                    }
                    System.out.println("Enter hardware name:");
                    String name = scanner.nextLine();
                    System.out.println("Enter hardware manufacturer:");
                    String manufacturer = scanner.nextLine();
                    System.out.println("Enter hardware price:");
                    double price = scanner.nextDouble();
                    scanner.nextLine();
                    hardware.name = name;
                    hardware.manufacturer = manufacturer;
                    hardware.price = price;
                    storageSystem.add(hardware);
                    break;
                case 2:
                    System.out.println("Enter hardware name to remove:");
                    name = scanner.nextLine();
                    Hardware hardwareToRemove = storageSystem.search(name);
                    if (hardwareToRemove != null) {
                        storageSystem.remove(hardwareToRemove);
                    } else {
                        System.out.println("Hardware not found");
                    }
                    break;
                case 3:
                    System.out.println("Enter hardware name to search:");
                    name = scanner.nextLine();
                    Hardware searchedHardware = storageSystem.search(name);
                    if (searchedHardware != null) {
                        System.out.println("Found hardware: " + searchedHardware.name);
                    } else {
                        System.out.println("Hardware not found");
                    }
                    break;
                case 4:
                    System.out.println("Displaying all hardware:");
                    storageSystem.display();
                    break;
                case 5:
                    System.out.println("Count: " + storageSystem.count());
                    break;
                case 6:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}
