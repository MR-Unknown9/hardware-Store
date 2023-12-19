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

    void add() {
        Hardware hardware = null;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the piece name: ");
        String name = input.nextLine();
        System.out.println("Enter manufacturer name: ");
        String manu = input.nextLine();
        double price;
        while (true) {
            System.out.println("Enter price: ");
            String nprice = input.nextLine();

            try {
                price = Double.parseDouble(nprice);
                break;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input! Enter a number please.");
            }
        }

        System.out.println("Note: Please write without any spaces!");
        System.out.println("Enter hardware type: ");
        String type = input.nextLine().toLowerCase(); // Convert to lowercase for case-insensitivity

        switch (type) {
            case "cpu": {
                int cores;
                while (true) {
                    System.out.println("Enter number of cores: ");
                    String ncores = input.nextLine();

                    try {
                        cores = Integer.parseInt(ncores);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                double freq;
                while (true) {
                    System.out.println("Enter frequency : ");
                    String nfreq = input.nextLine();

                    try {
                        freq = Double.parseDouble(nfreq);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new CPU(name, manu, price, cores, freq);
                break;
            }
            case "gpu": {
                int memory;
                while (true) {
                    System.out.println("Enter gpu memory: ");
                    String nmemory = input.nextLine();

                    try {
                        memory = Integer.parseInt(nmemory);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new GPU(name, manu, price, memory);
                break;
            }
            case "ram": {
                int memory;
                while (true) {
                    System.out.println("Enter memory: ");
                    String nmemory = input.nextLine();

                    try {
                        memory = Integer.parseInt(nmemory);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                int speed;
                while (true) {
                    System.out.println("Enter speed: ");
                    String nspeed = input.nextLine();

                    try {
                        speed = Integer.parseInt(nspeed);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new RAM(name, manu, price, memory, speed);
                break;
            }
            case "storageunit": {
                int size;
                while (true) {
                    System.out.println("Enter size: ");
                    String nsize = input.nextLine();
                    try {
                        size = Integer.parseInt(nsize);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                System.out.println("Enter type: ");
                String stype = input.nextLine();
                hardware = new StorageUnit(name, manu, price, size, stype);
                break;
            }
            case "motherboard": {
                System.out.println("Enter model: ");
                String model = input.nextLine();
                hardware = new Motherboard(name, manu, price, model);
                break;
            }
            case "powersupply": {
                int wattage;
                while (true) {
                    System.out.println("Enter wattage: ");
                    String nwattage = input.nextLine();

                    try {
                        wattage = Integer.parseInt(nwattage);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                System.out.println("Enter efficiency: ");
                String eff = input.nextLine();
                hardware = new PowerSupply(name, manu, price, wattage, eff);
                break;
            }
            case "coolingsystem": {
                System.out.println("Enter type: ");
                String ctype = input.nextLine();
                hardware = new CoolingSystem(name, manu, price, ctype);
                break;
            }
            case "case": {
                System.out.println("Enter size: ");
                String size = input.nextLine();
                System.out.println("Enter color: ");
                String color = input.nextLine();
                hardware = new Case(name, manu, price, size, color);
                break;
            }
            case "peripheral": {
                System.out.println("Enter connection type: ");
                String con = input.nextLine();
                System.out.println("Enter Peripheral type: ");
                String ptype = input.nextLine();
                hardware = new Peripheral(name, manu, price, con, ptype);
                break;
            }
            default: {
                System.out.println("Invalid hardware type!");
                break;
            }
        }

        if (hardware != null) {
            this.hardwareList.add(hardware);
            System.out.println("Hardware added successfully!");
        }
        input.close();
    }

    void removeHardwareByName(String name) {
        Hardware hardwareToRemove = null;

        for (Hardware hardware : hardwareList) {
            if (hardware.name.equals(name)) {
                hardwareToRemove = hardware;
                break;
            }
        }

        if (hardwareToRemove != null) {
            hardwareList.remove(hardwareToRemove);
            System.out.println("Removed hardware with name: " + name);
        } else {
            System.out.println("Hardware with name " + name + " not found.");
        }
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
                System.out
                        .println("NAME: " + cpu.name + ", TYPE: " + type + ", PRICE: " + cpu.price + ", MANUFACTURER: "
                                + cpu.manufacturer + ", CORES: " + cpu.cores + ", FREQUENCY: " + cpu.frequency);
            } else if (hardware instanceof GPU) {
                type = "GPU";
                GPU gpu = (GPU) hardware;
                System.out.println("NAME: " + gpu.name + ", TYPE: " + type + ", PRICE: " + gpu.price
                        + ", MANUFACTURER: " + gpu.manufacturer + ", MEMORY: " + gpu.memory);
            } else if (hardware instanceof RAM) {
                type = "RAM";
                RAM ram = (RAM) hardware;
                System.out
                        .println("NAME: " + ram.name + ", TYPE: " + type + ", PRICE: " + ram.price + ", MANUFACTURER: "
                                + ram.manufacturer + ", CAPACITY: " + ram.capacity + ", SPEED: " + ram.speed);
            } else if (hardware instanceof StorageUnit) {
                type = "Storage Unit";
                StorageUnit storageUnit = (StorageUnit) hardware;
                System.out.println("NAME: " + storageUnit.name + ", TYPE: " + type + ", PRICE: " + storageUnit.price
                        + ", MANUFACTURER: " + storageUnit.manufacturer + ", CAPACITY: " + storageUnit.capacity
                        + ", TYPE: " + storageUnit.type);
            } else if (hardware instanceof Motherboard) {
                type = "Motherboard";
                Motherboard motherboard = (Motherboard) hardware;
                System.out.println("NAME: " + motherboard.name + ", TYPE: " + type + ", PRICE: " + motherboard.price
                        + ", MANUFACTURER: " + motherboard.manufacturer + ", MODEL: " + motherboard.model);
            } else if (hardware instanceof PowerSupply) {
                type = "Power Supply";
                PowerSupply powerSupply = (PowerSupply) hardware;
                System.out.println("NAME: " + powerSupply.name + ", TYPE: " + type + ", PRICE: " + powerSupply.price
                        + ", MANUFACTURER: " + powerSupply.manufacturer + ", WATTAGE: " + powerSupply.wattage
                        + ", EFFICIENCY: " + powerSupply.efficiency);
            } else if (hardware instanceof CoolingSystem) {
                type = "Cooling System";
                CoolingSystem coolingSystem = (CoolingSystem) hardware;
                System.out.println("NAME: " + coolingSystem.name + ", TYPE: " + type + ", PRICE: " + coolingSystem.price
                        + ", MANUFACTURER: " + coolingSystem.manufacturer + ", TYPE: " + coolingSystem.type);
            } else if (hardware instanceof Case) {
                type = "Case";
                Case caseHardware = (Case) hardware;
                System.out.println("NAME: " + caseHardware.name + ", TYPE: " + type + ", PRICE: " + caseHardware.price
                        + ", MANUFACTURER: " + caseHardware.manufacturer + ", SIZE: " + caseHardware.size + ", COLOR: "
                        + caseHardware.color);
            } else if (hardware instanceof Peripheral) {
                type = "Peripheral";
                Peripheral peripheral = (Peripheral) hardware;
                System.out.println("NAME: " + peripheral.name + ", TYPE: " + type + ", PRICE: " + peripheral.price
                        + ", MANUFACTURER: " + peripheral.manufacturer + ", TYPE: " + peripheral.type + ", CONNECTION: "
                        + peripheral.connection);
            }
        }
    }

    int count() {
        return this.hardwareList.size();
    }

    void sortHardwareByPrice() {
        int n = this.hardwareList.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (this.hardwareList.get(j).price > this.hardwareList.get(j + 1).price) {
                    // swap hardwareList[j+1] and hardwareList[j]
                    Hardware temp = this.hardwareList.get(j);
                    this.hardwareList.set(j, this.hardwareList.get(j + 1));
                    this.hardwareList.set(j + 1, temp);
                }
            }
        }
    }

}

public class test {
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
                    storageSystem.add();
                    break;
                case 2:
                    System.out.println("Enter hardware name to remove:");
                    String name = scanner.nextLine();
                    storageSystem.removeHardwareByName(name);
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
                    storageSystem.sortHardwareByPrice();
                    System.out.println("Hardware sorted by price.");
                    storageSystem.display();
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
