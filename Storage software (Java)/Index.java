import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        StorageSystem storageSystem = new StorageSystem();
        Scanner scanner = new Scanner(System.in);
        boolean flag = true;

        // while (true) {
        // System.out.println("Please choose an option:");
        // System.out.println("1. Add hardware");
        // System.out.println("2. Remove hardware");
        // System.out.println("3. Search for hardware");
        // System.out.println("4. Display all hardware");
        // System.out.println("5. Count hardware");
        // System.out.println("6. Sort By Price");
        // System.out.println("7. Exit");

        // int option = scanner.nextInt();
        // scanner.nextLine();

        // switch (option) {

        // case 1:
        // storageSystem.add();
        // break;
        // case 2:
        // System.out.println("Enter hardware name to remove:");
        // String name = scanner.nextLine();
        // storageSystem.removeHardwareByName(name);
        // scanner.close();
        // break;

        // case 3:
        // System.out.println("Enter hardware name to search:");
        // name = scanner.nextLine();
        // Hardware searchedHardware = storageSystem.search(name);
        // if (searchedHardware != null) {
        // System.out.println("Found hardware: " + searchedHardware.name);
        // } else {
        // System.out.println("Hardware not found");
        // }
        // scanner.close();
        // break;
        // case 4:
        // System.out.println("Displaying all hardware:");
        // storageSystem.display();
        // break;
        // case 5:
        // System.out.println("Counting hardware by type:");
        // storageSystem.countHardwareByType();
        // break;
        // case 6:
        // storageSystem.sortHardwareByPrice();
        // System.out.println("Hardware sorted by price.");
        // storageSystem.display();
        // break;
        // case 7:
        // System.out.println("Exiting...");
        // break;
        // default:
        // System.out.println("Invalid option. Please try again.");

        // }
        // }
        // }
        while (flag) {

            System.out.println("Please choose an option:");
            System.out.println("1. Add hardware");
            System.out.println("2. Remove hardware");
            System.out.println("3. Search for hardware");
            System.out.println("4. Display all hardware");
            System.out.println("5. Count hardware");
            System.out.println("6. Sort By Price");
            System.out.println("7. Exit");

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
                    scanner.close();
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
                    scanner.close();
                    break;
                case 4:
                    System.out.println("Displaying all hardware:");
                    storageSystem.display();
                    break;
                case 5:
                    System.out.println("Counting hardware by type:");
                    storageSystem.countHardwareByType();
                    break;
                case 6:
                    storageSystem.sortHardwareByPrice();
                    System.out.println("Hardware sorted by price.");
                    storageSystem.display();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    flag = false;
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");

            }
        }
    }
}
