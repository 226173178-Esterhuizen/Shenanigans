# Individual contribution record

## 1. Identification data
* **Student Name:** Bea Esterhuizen
* **Student Number:** 226173178
* **System Responsibility:** System testing, documentation and Git Coordination

## 2. Functions and source modules developed
Primary programmatic mandate was establishes a automated tracking framwork to evaluate the structural intefrity of the application layer. I made and deployed the following system components directly in the root directory:

#### 2.1 Header Interface (`testing.h`)
* Developed strict conditional macro configuration wrappers (`#ifdef TESTING_H`, `#define TESTING.H`, `#endif`) to prevent duplicate compilation loops inside the multifile architecture.
* Declared the global tracking entry routine prototype: `void runSystemTests();`.

### 2.2 Execution Engine (`testing.c`)
* **`runSystemTests()`**: Coded the automated test execution suite mapped directly to *option6* in the main user console shell menu.
* **Simulated Module Probes**: Programmed distinct validation checks (`testEmployeeModule`, `testBudgetModule`, `testSupplierModule`, `testAssetModule`, `testReportsModule`, `testValidationUnit`) to probe array bounds and crossfile linkage stability.
* **Diagnostic summary generator**: Coded log printouts that calculate total passing evaluation tests and report system deployment readiness status.

## 3. GitHub and version control contribution activity
As team Git coordinator, managing groups central cloud workspace repository, resolving version blockages and maintained alignment across all functional layers is my duty.

* **Repository Initialization:** Created master architecture frame, directories and blank multivariable blueprint templates for all group members.
* **Divergent History Reconciliation:** Managed incoming features from disconnected developer branches by forcing local overrides using specialized integration parameters (`--allow-unrelated-histories`, `--no-ff`, and `-X ours`) to bypass fast-forward blockages on GitHub.
* **Conflict Resolution Matrices:** Audited file collisions in `main.c` and header records caused by mismatched team files, restoring system linkage stability.

## 4. Testing Performed
To make sure software is stable before building, I executed the following validation protocols using the custom diagnostics suite:

| Test Target Vector | Input Stimulus Evaluated | Expected Automated Result | Actual Status Output |
| :--- | :--- | :--- | :--- |
| **System Diagnostics** | Menu Option `6` | Initiate full multimodule sweep | **[ PASS ]** Diagnostics complete |
| **Linkage Verification** | Modular Probe Calls | All 7 checkpoints return `[ OK ]` | **[ PASS ]** Links verified |
| **Boundary Filtering** | Character Stream Injection | Intercept buffer loops | **[ PASS ]** Swaps processed safely |
| **Menu Interception** | Out-of-bounds selection (`8`) | Redirect to default handler | **[ PASS ]** Invalid option caught |
| **Termination Bounds** | Menu Option `7` | Intercept console loop | **[ PASS ]** Exiting system. Goodbye. |

## 5. Summary of indivdual understanding
Mosly successfully executed my assigned duties. Also applied core programming concepts learned and demostrated ability to organize a multi-file program, make traking interfaces, devensive integration pipelines and make software configuration metrics required to build a sound codebase baseline.