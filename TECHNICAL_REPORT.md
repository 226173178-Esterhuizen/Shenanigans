# Tecnical Architechture and Systems Integration Report

## Project Infor:
* **Course:** PAP521S
* **Development stage:** Project A Foundation System

## 1. Introduction
Modern local government operations require robust auditable computational systems to oversee public assets, distribute employee compensation and mainting transparent procurement workflows. This technical report details the systemic architectural design of the baseline MFMS made for Project A. The project has been made from its inception to emphasize structural encapsulation, multi-file source separation and strict input validation boundaries.

## 2. Problem Description
Municipalities handle vast amounts of disconnected tracking vectors spanning multiple distinct departments. Managing financial registers using flat files or single-threaded legacy architechture often causes serious problems including:
* Data isolation across payroll, budgeting and asset tracking.
* Data corruption due to unvalidated out-ofbounds user entries.
* Code management issues when multiple software developers work inside a single giant source script.

The core challenge is to builg a foundation tracking utility using C, that integratess business tracking areas into an organised menu driven interface.

## 3. System Objectives
to address operational issues listed above the system design achieves the following programming milestones:

1. **Modular architecture:** Remove monolithic `main()` design by separating individual components into discrete header (`.h`) and source code implementation (`.c`) modules.
2. **Defensive Validation Boundaries:** Prevent arithmetic calculation overflow or corruption by intrecepting invalid menu choices and filtering out negative monetary bounds.
3. **Execution Pipeline Stability:** Demonstrate a reliable workflow structured around the core lifecycle of data management:
\[\text{Input} \longrightarrow \text{Processing} \longrightarrow \text{Storage} \longrightarrow \text{Search} \longrightarrow \text{Calculation} \longrightarrow \text{Output}\]

## 4. System features
The system establishes five independant domain-specific subsystems accessible through a centralised interactive control panel:
* **Employee Management:** Handles staff tracking records, housing allocations and basic salary parameters.
* **Budget Management:** Tracks real-time departmental allocations and logs expense variances against remaining balances.
* **Supplier Management:** Hosts procurement contacts, email coordinates and geographical branch tracking tables.
* **Asset Management:** Maintains an inventory register of municipal infrastructure, operational status metrics and equipment valuations.
* **Centralized Diagnostic Module:** A dedicated debugging layer controlled by Bea(student 7) to run diagnostic health checks across the application framework.

## 5. Program design
The program architecture uses a decoupled structural paradigm to partition the workspace and enable clean parallel developmet across the team.

#### Structural Map of System Components
```text
[main.c] (Centralized Control Loop)
   ▼
 ├── [employees.h]  ──► [employees.c] (Johannes - Staff Records)
 ├── [budget.h]     ──► [budget.c]    (If-Pio - Allocation Models)
 ├── [suppliers.h]  ──► [suppliers.c] (Magnus - Vendor Procurement)
 ├── [assets.h]     ──► [assets.c]    (Simataa - Asset Registers)
 ├── [reports.h]    ──► [reports.c]   (Elvis - Multi-Module Calculations)
 └── [testing.h]    ──► [testing.c]   (Bea - Automation Suite)
```
The system control engine uses a continuous loop (`while(1)`) tied to an evaluated switch-case block. This structure routes the user to separate execution paths while checking `scanf` return states to prevent invalid non-interger inputs from causing terminal loops.

## 6. Challenges Ecountered
During early local integration passes 2 distinct issues appeared:
1. **Terminal input loop flaws:** If user accidently types a non-numeric characterinto the numeric menu prompt `scanf` would fail to read it. This left the bad character behind in the input stream causing the terminal loop to spin out of control.
2. **Local Environment workspace splits / divereged branches:** Working with 7 team members simultaneously risked serious version control control blockes. Git and complier paths were initially missing from system `PATH` variables on multiple on multiple local environment. GitHub blocked incoming pull requests due to entirely disconnected branch histories.

## 7. Solutions Implemented
To resolve these architectural issues the following things were integrated:
1. **Flushing the input buffer:** added a dedicated stream-clearing fallback check using `while (getchar() != '\n');`. This instantly flushes the input buffer when `scanf` returns a invalid token match successfully resseting the prompt.
2. **Environment PATH and unrelated Histories resolution:** System environmental PATH configurations were corrected to allow CLI for git and GCC. Disconnected upstream histories were unified from the terminal by running custom overrides utilisation `git pull origin [branch-name] --allow-unrelated-histories` paired with `git checkout --ours` to resolve file structure collisions.
3. **Header gaurds enforcement:** Implementated standard conditional macro wrapperss (`#ifndef`, `#define`, `#endif`) across all component headers to prevent duplicate compliation problems.

## 8. Conclusion
The foundation of Project A successfully establishes a stable modular framework for the MFMS. By breaking the project out into clean files and protecting them with validation checks and header gaurds the system avoids common monolithic development bottlenecks. This core setup provides a reliable, conflict free plateform for the rest of the group to build their features.