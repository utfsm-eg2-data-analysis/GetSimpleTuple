#!/bin/bash

##############################################################
# ./send_GST_JLabSim.sh <target> <ndir>                      #
#     <target> = (D, C, Fe, Pb)                              #
#     <ndir>   = (1 - 9)                                     #
#                                                            #
# EG: ./send_GST_JLabSim.sh C 1                              #
#     ./send_GST_JLabSim.sh Fe 2                             #
#     ./send_GST_JLabSim.sh Pb 3                             #
#     ./send_GST_JLabSim.sh D 4                              #
##############################################################

#####
# Input
###

INPUTARRAY=("$@")

TARNAME=${INPUTARRAY[0]}
NDIR=${INPUTARRAY[1]}

if [[ "$TARNAME" != "D" && $NDIR -lt 4 ]]; then
    CURRENTDIR="${TARNAME}${NDIR}"
elif [[ "$TARNAME" != "D" && $NDIR -gt 3 ]]; then
    CURRENTDIR="${TARNAME}${NDIR}_yshiftm03";
elif [[ "$TARNAME" == "D" && $NDIR -lt 4 ]]; then
    CURRENTDIR="${TARNAME}2_pb${NDIR}"
elif [[ "$TARNAME" == "D" && $NDIR -gt 3 ]]; then
    CURRENTDIR="${TARNAME}2_pb${NDIR}_yshiftm03"
fi

SUFIX="${TARNAME}" # usually, the end of the root files is like this
if [[ "$TARNAME" == "D" ]]; then SUFIX="${TARNAME}2_Pb"; fi # except for D

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
GSTDIR=${HOME}/volatile/GetSimpleTuple                             # dir of the executable
SIMDIR=${HOME}/work/sim/Full_HSim/${CURRENTDIR}                    # dir where are located all the HSims
OUTDIR=${HOME}/work/sim/out/GetSimpleTuple_HSim/${CURRENTDIR}      # output dir
TMPDIR=${HOME}/work/sim/tmp/GetSimpleTuple_HSim/${CURRENTDIR}      # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case

# setting jobname
jobname="GST_HSim_${TARNAME}${NDIR}"
jobfile="${TMPDIR}/${jobname}.sh"

echo ${jobname}

echo "#!/bin/bash"                                                 > ${jobfile}
echo "#SBATCH -A clas"                                            >> ${jobfile}
echo "#SBATCH -J ${jobname}"                                      >> ${jobfile}
echo "#SBATCH -o ${TMPDIR}/${jobname}.out"                        >> ${jobfile}
echo "#SBATCH -e ${TMPDIR}/${jobname}.err"                        >> ${jobfile}
echo "#SBATCH --time=3:00:00"                                     >> ${jobfile} # 4hrs or 15min for test
echo "#SBATCH --mem-per-cpu=500M"                                 >> ${jobfile}
echo "#SBATCH --mail-user=claudio.sanmartinval@gmail.com"         >> ${jobfile}
echo "#SBATCH --mail-type=BEGIN,END,FAIL"                         >> ${jobfile}
echo ""                                                           >> ${jobfile}
echo "source ${HOME}/.bashrc"                                     >> ${jobfile}
echo "cp ${GSTDIR}/bin/GetSimpleTuple_sim ${TMPDIR}"              >> ${jobfile} # retrieve executable
echo "cd ${TMPDIR}"                                               >> ${jobfile}

NFILES=$(ls -1 ${SIMDIR} | wc -l)
NSIMS=0

for ((RN=1; RN <= 500; RN++)); do # Files were enumerated up to 500, but there might be missing files
    if [[ -e ${SIMDIR}/simul_${SUFIX}${RN}.root ]]; then
    	inputfile=$(readlink -f ${SIMDIR}/simul_${SUFIX}${RN}.root)                 # retrieve full path of input file (with $SUFIX)
    	echo "ln -s ${inputfile} recsis${TARNAME}_${RN}.root"         >> ${jobfile} # create symbolic link to input file with GST naming scheme
    	echo "./GetSimpleTuple_sim -t${TARNAME} -r${RN}"              >> ${jobfile} # execute program
    	echo "mv -v pruned${TARNAME}_${RN}.root ${OUTDIR}/"           >> ${jobfile} # move outfile to outdir
    	echo "rm -v recsis${TARNAME}_${RN}.root"                      >> ${jobfile} # removing symbolic link from temp dir
    	echo ""                                                       >> ${jobfile}
	((NSIMS++))
    fi
done
echo "rm GetSimpleTuple_sim"                                          >> ${jobfile} # remove binary from temp dir
echo "Submitting job: ${jobfile}"
echo "Number of simulation files: ${NSIMS} out of ${NFILES}"
sbatch ${jobfile} # submit job!
