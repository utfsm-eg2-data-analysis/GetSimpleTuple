GetSimpleTuple
==============

## About this branch
---

This branch (`aborquez/analysis-omega`) differs from `main` and `development` in these areas:

* Electron ID and photons ID adapted from the CLAS Analysis Note of Taisiya Mineeva

* Charged Pions ID adapted from the CLAS Analysis Note of Sebastián Morán

* It has *most* of the Quality-of-Life (QOL) changes of `development`, but maintains the **flat-format** of `main`

* It requires the **ClasTool** from [**clas_package**](http://github.com/utfsm-eg2-data-analysis/clas_package)

* To avoid repetition, this branch doesn't store scripts for sending jobs

* Removed `Status` as variables to make files lighter

* Incorporates **parent id** information of the generated simulations

## Requirements
---

* **ROOT**

* [**ClasTool**](http://github.com/utfsm-eg2-data-analysis/clas_package)

## Compilation
---
Compile by running `make`.

## Execution
---

```
./GetSimpleTuple_[data-type] -t[target] -r[run-number]
```

Where:

* `[data-type]`
  : can be `data` or `sim` to choose between data and simulations, respectively.

  * If it's `data`, a set of files with the following filename scheme are required: `clas_<run-number>_*.pass2.root`

  * If it's `sim`, one file with the following filename scheme is required: `recsis<target>_<run-number>.root`

* `[target]`
  : can be `D`, `C`, `Fe`, or `Pb`

* `[run-number]`
  : corresponds to the run number of the file(s)

## Examples
---

If you have all the files from the run number `42011`, the following command will parse all of them:

```
./GetSimpleTuple_data -tC -r42011
```

On the other hand, to read a `D` simulation file, you must execute:

```
./GetSimpleTuple_sim -tD -r00
```
