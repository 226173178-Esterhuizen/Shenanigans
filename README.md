# Municipal Financial Management System (MFMS)

## Project details:
* **Course:** Programming in Practice
* **Group Members:** Bea Esterhuizen(226173178), Elvis Masule(226077063), Magnus Nuumbembe(226043061), Saara Lita(226174301), Simataa Mushaukwa(2226077065), Johannes Silas(226043908), If-Pio Iyambo(226095568).
## System Description
The Municipal Financial Management System (MFMS) is a modular console based application written in C. The system acts as a management panel designed for municipal administrators to handle employee databases, financial budget allocations, supplier tracking, asset indices, reporting matrices and secure data formatting filters safely from a single executable program environment.

## Individual System Contribution Matrix
This matrix serves as the official operational guide mapping individual project deliverables back to active development lines:

| Student Developer | Target Code Modules | Core Project Contribution Role |
| :--- | :--- | :--- |
| **Johannes** | `employees.c` / `employees.h` | Employee Management tracking databases. |
| **If-pio** | `budget.c` / `budget.h` | Financial allocation indices and balance ledgers (Budget Management). |
| **Magnus** | `suppliers.c` / `suppliers.h` | Third-party vendor procurement tracking (Supplier Management). |
| **Simataa** | `assets.c` / `assets.h` | Property tracking registries and appraisal logs (Asset Management). |
| **Elvis** | `reports.c` / `reports.h` | Aggregate calculation outputs and text exports (Report Module). |
| **Saara** | `validation.c` / `validation.h` | Robust numeric data validation engine (Functions, integrastion and validation). |
| **Bea** | `testing.c` / `testing.h` | Diagnostics suite, Git coordination & documentation. |

## Complete Compilation and Execution Guide
Because this is a strict modular engineering project, all `.c` dependencies should be linked together in parallel during compilation. Run the following commands in your terminal workspace:

````bash
# Compilation String (Builds entire system together)
gcc main.c testing.c employees.c budget.c suppliers.c assets.c reports.c validation.c -o mfms_system

# Execution Command (Windows PowerShell)
.\mfms_system.exe
````

## System Diagnostics Module
Selection **Option 6** from the central system shell menu launches an automated structural diagnostics suite managed within `testing.c`. The module queries active operational components, triggers validation loops and performs interface verification sweeps to guarantee baseline stability. 