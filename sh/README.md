# GetSimpleTuple/sh

## send_GST_HSim.sh

This Bash script creates a job file that is submitted into the USM farm, that is in charge of executing **GetSimpleTuple**
for all the root files inside a Hayk's simulation directory.

Usage is:

```
./send_GST_HSim.sh <target> <ndir>
```

where:

* `<target> = (D, C, Fe, Pb)`

* `<ndir> = (1 - 9)`

Feel free to edit the directories `SIMDIR`, `GSTDIR`, `OUTDIR`, `TMPDIR` at convenience.
The directory `SIMDIR` and the naming scheme of the input files is described within the script.

To run the full sample of simulations, you should run all <ndir> for each <target>, that would be a total of 36 jobs.
