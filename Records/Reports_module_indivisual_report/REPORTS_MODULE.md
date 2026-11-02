# Individual Contribution Record

## 1. Identification Data

- **Student Name:** Elvis Masule
- **Student Number:** [Insert student number]
- **System:** Municipal Financial Management System
- **System Responsibility:** Reports Management Module

## 2. Functions and Source Modules Developed

My assigned responsibility was the development of the **Reports Management Module**, which provides console-based summaries and listings of information maintained by other components of the Municipal Financial Management System.

I implemented the module in two files:

### 2.1 Header Interface (`reports.h`)

The header file provides declarations and data structures required by the reporting module and other source files.

- **Header guard:** Implemented `#ifndef REPORTS_H`, `#define REPORTS_H`, and `#endif` to prevent repeated inclusion.
- **Project dependencies:** Included `employees.h` and `suppliers.h` to access the `Employee` and `Supplier` structures.
- **Constants:** Defined maximum character-array sizes: `MAX_NAME`, `MAX_EMAIL`, `MAX_PHONE`, `MAX_LOCATION`, `MAX_TYPE`, and `MAX_CONDITION`.
- **Budget structure:** Defined `Budget`, containing the department name, allocated budget, and expenditure.
- **Asset structure:** Defined `Asset`, containing the asset ID, name, type, purchase value, department, and condition.
- **Function prototypes:** Declared the four report-generation functions and `displayReportsMenu()`.

### 2.2 Reporting Implementation (`reports.c`)

This file implements report generation, menu navigation, input handling, calculations, and formatted console output.

- **`readIntegerInput()`**: A private helper that reads an integer menu selection. It checks whether `scanf()` successfully converts the input and attempts to clear the remaining input line when conversion fails. It is declared `static` because it is only required inside `reports.c`.
- **`generateEmployeeReport()`**: Calculates each employee's total salary by adding basic salary, housing allowance, and transport allowance. It then calculates the total and average salary and identifies the highest and lowest total salaries. The report displays the employee count and salary statistics.
- **`generateBudgetReport()`**: Calculates total allocated budget, total expenditure, and remaining budget across departments. It also identifies departments whose expenditure exceeds their allocation and displays the amount overspent.
- **`generateSupplierReport()`**: Displays supplier ID, name, email, phone number, and location in a formatted table, together with the total number of registered suppliers.
- **`generateAssetReport()`**: Lists asset IDs, names, types, purchase values, departments, and conditions. It also calculates the combined purchase value of all listed assets.
- **`displayReportsMenu()`**: Provides access to individual reports, all reports, and the option to return to the main menu. A `while` loop keeps the menu active, while a `switch` statement processes the selected option.

The report functions receive arrays and record counts as parameters. Their record arrays are declared `const`, indicating that the reporting functions are intended to read the supplied records rather than modify them.

## 3. Libraries and Programming Concepts Applied

### 3.1 Libraries and header dependencies

| Header | Purpose |
|---|---|
| `<stdio.h>` | Provides console input and output functions such as `printf()`, `scanf()`, and `getchar()`. |
| `<string.h>` | Included in `reports.c`, although no string-handling function from this library is currently used. |
| `"reports.h"` | Provides the module's structures, constants, function declarations, and project-header dependencies. |
| `"employees.h"` | Supplies the `Employee` structure used by the employee report; included through `reports.h`. |
| `"suppliers.h"` | Supplies the `Supplier` structure used by the supplier report; included through `reports.h`. |

### 3.2 Programming concepts

- **Modular programming:** Separates declarations in `reports.h` from implementations in `reports.c`.
- **Structures:** Groups related employee, budget, supplier, and asset information into records.
- **Arrays:** Allows functions to process collections of records.
- **Functions and parameters:** Divides reporting tasks into reusable functions and receives data from other modules through parameters.
- **Loops:** Uses `for` loops to process records and a `while` loop to keep the reports menu running.
- **Conditional statements:** Uses `if` statements to handle empty records, compare salaries, and identify overspending.
- **Switch-case selection:** Uses a `switch` statement to respond to menu selections.
- **Input validation:** Checks whether menu input can be converted to an integer.
- **Formatted output:** Uses `printf()` format specifiers to display aligned tables and monetary values to two decimal places.
- **Read-only parameters:** Uses `const` for report-array parameters to help protect supplied records from modification.

## 4. Problems Encountered and Technical Considerations

The following are relevant technical challenges and considerations for developing and integrating this module. They describe issues addressed by the implementation or areas requiring care; they should not be treated as claims of specific incidents unless they were actually encountered.

### 4.1 Integrating data structures from other modules

The employee and supplier reports depend on structures declared in other project headers. Differences in field names or data types could prevent the reporting module from compiling.

**Approach:** Included the relevant project headers through `reports.h` and used the shared `Employee` and `Supplier` structures. Successful integration requires the fields accessed in `reports.c` to match the actual shared structure definitions.

### 4.2 Handling empty records

Calculating an average or accessing an array when no records are available could cause invalid calculations or memory-access problems.

**Approach:** Each report checks whether its record count is less than or equal to zero. If no records are available, it displays a message and returns before processing the array.

### 4.3 Calculating financial summaries correctly

The employee report combines several salary components, while the budget report aggregates values across departments and compares expenditure with allocations.

**Approach:** Used `double` variables for monetary calculations and running totals. The budget report checks each department individually so that overspending is identified rather than relying only on the overall budget balance.

### 4.4 Handling invalid menu input

Users may enter letters or other non-numeric characters when the menu expects an integer. If invalid characters remain in the input stream, subsequent menu reads may fail.

**Approach:** Created `readIntegerInput()` to check the return value of `scanf()`. When conversion fails, the function attempts to clear the rest of the current input line and returns `-1`, allowing the menu's default case to handle the invalid selection.

**Remaining limitation:** The current input-clearing loop does not explicitly handle end-of-file. A more robust implementation could use `fgets()` and `strtol()` and validate the complete input line.

### 4.5 Keeping console tables readable

Long names, email addresses, locations, and department names can exceed the widths allocated in formatted output and affect table alignment.

**Approach:** Used field-width specifiers in `printf()` to organise output into columns, with headings and separator lines.

**Possible improvement:** Apply deliberate truncation or dynamic-width formatting for long values.

### 4.6 Maintaining consistency during team integration

The reporting module depends on the function signatures and structure definitions used by the wider system. Changes made independently in other modules can affect compilation and integration.

**Approach:** Kept public function declarations in `reports.h` and passed the required arrays and counts into the menu function. This reduces unnecessary dependence on global variables and makes the data required by the reporting functions explicit.

## 5. Testing and Verification Considerations

The implementation includes checks for empty records and invalid menu selections. The following cases are appropriate for verifying the module during integration:

| Test area | Test input or condition | Expected behaviour |
|---|---|---|
| Employee report | No employee records (`count <= 0`) | Displays a no-records message without calculating an average. |
| Employee report | Multiple employees with different total salaries | Displays the correct count, average, highest, and lowest total salary. |
| Budget report | Departments below, equal to, and above allocation | Calculates totals and lists only departments exceeding allocation. |
| Supplier report | No supplier records | Displays a no-records message. |
| Supplier report | One or more supplier records | Displays supplier details and the registered supplier count. |
| Asset report | No asset records | Displays a no-records message. |
| Asset report | Multiple asset records | Lists assets and calculates their combined purchase value. |
| Reports menu | Options 1 to 5 | Opens the selected report or displays all four reports. |
| Reports menu | Option 6 | Displays the return message and exits the reports menu. |
| Reports menu | Integer outside 1 to 6 | Displays the invalid-selection message and repeats the menu. |
| Input handling | Non-numeric menu input | Returns an invalid value and allows the menu's default case to handle it. |

These are test cases derived from the implementation. Actual test results should only be recorded after the cases have been run against the integrated application.

## 6. Integration with the Municipal Financial Management System

The Reports Management Module is designed to work with the wider system rather than operate as a separate record-management application.

The main program or relevant management components supply the employee, budget, supplier, and asset arrays, together with their record counts, when calling `displayReportsMenu()`.

The menu then directs the supplied records to the appropriate report-generation function. This separates the responsibility for maintaining records from the responsibility for presenting summaries and listings.

For integration, the project must compile `reports.c` with the other required source files. The relevant headers must be accessible to the compiler, and the `Employee` and `Supplier` structures must contain the fields referenced by this module.

## 7. Summary of Individual Understanding

Through the development of the Reports Management Module, I applied core C programming concepts to produce a component that presents municipal employee, budget, supplier, and asset information in an organised format.

I gained practical experience in separating header declarations from implementation code, using structures and arrays across modules, processing records with loops, performing financial calculations, validating menu input, and presenting information through formatted console output.

The work also highlighted the importance of consistent shared structures and function declarations when multiple developers contribute to one multi-file application.

The module provides the core reporting functionality required by its assigned responsibility. Further improvements could include stronger line-based input validation, more flexible table formatting, report export, and additional budget-performance indicators.

## 8. Contribution Summary

| File or function | Contribution |
|---|---|
| `reports.h` | Defined the `Budget` and `Asset` structures, constants, header dependencies, and public function prototypes. |
| `reports.c` | Implemented reporting functionality, the input helper, calculations, menu navigation, and formatted output. |
| `generateEmployeeReport()` | Summarises employee salary information. |
| `generateBudgetReport()` | Summarises budget allocations and expenditure and identifies overspending departments. |
| `generateSupplierReport()` | Lists registered suppliers. |
| `generateAssetReport()` | Lists registered assets and calculates their total purchase value. |
| `displayReportsMenu()` | Provides access to individual reports and the option to display all reports. |
| `readIntegerInput()` | Handles integer input for the reports menu. |

**End of Individual Contribution Record**
