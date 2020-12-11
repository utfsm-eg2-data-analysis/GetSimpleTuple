#!/bin/bash

##############################################################
# ./send_GST_data.sh <target>                                #
#     <target> = (C, Fe, Pb)                                 #
#                                                            #
# EG: ./send_GST_data.sh C                                   #
#     ./send_GST_data.sh Fe                                  #
#     ./send_GST_data.sh Pb                                  #
##############################################################

#####
# Input
###

TARNAME="$@"

#####
# Main
###

# set env
source ~/.bashrc

# set main dirs
GSTDIR=${HOME}/GetSimpleTuple                                              # dir of the executable
DATADIR=/data/jlab/mss/clas/eg2a/production/Pass2/Clas                     # dir where are located all the data files
OUTDIR=/eos/user/${USER:0:1}/${USER}/out/GetSimpleTuple_data/${TARNAME}    # output dir
TMPDIR=/eos/user/${USER:0:1}/${USER}/tmp/GetSimpleTuple_data/${TARNAME}    # temp dir to store logs and job scripts
mkdir -p ${OUTDIR} ${TMPDIR} # just in case

# obtain run numbers
if [[ "${TARNAME}" == "C" ]]; then
    RNLIST=${GSTDIR}/include/C-thickD2rn.txt
elif [[ "${TARNAME}" == "Fe" ]]; then
    RNLIST=${GSTDIR}/include/Fe-thickD2rn.txt
elif [[ "${TARNAME}" == "Pb" ]]; then
    RNLIST=${GSTDIR}/include/Pb-thinD2rn.txt
fi
TOTALRN=$(wc -l < ${RNLIST}) # total number of run numbers

for ((COUNTER=1; COUNTER <= ${TOTALRN}; COUNTER++)); do # ${nfiles} or 1
    # update rn value
    RN=$(sed -n "$COUNTER{p;q}" ${RNLIST}) # data from RNLIST

    # setting jobname
    jobname="GST_data-${TARNAME}_${RN}"
    jobfile="${TMPDIR}/${jobname}.sh"

    echo ${jobname}

    echo "#!/bin/bash"                                                 > ${jobfile}
    echo "#SBATCH -J ${jobname}"                                      >> ${jobfile}
    echo "#SBATCH -o ${TMPDIR}/${jobname}.out"                        >> ${jobfile}
    echo "#SBATCH -e ${TMPDIR}/${jobname}.err"                        >> ${jobfile}
    echo "#SBATCH --time=4:00:00"                                     >> ${jobfile} # 4hrs or 15min for test
    echo "#SBATCH --mem=1GB"                                          >> ${jobfile}
    echo ""                                                           >> ${jobfile}
    echo "source ${HOME}/.bashrc"                                     >> ${jobfile}
    echo "cd ${GSTDIR}/bin"                                           >> ${jobfile}
    for file in ${DATADIR}/clas_${RN}*; do # extract all run numbers
	inputfile=$(readlink -f ${file})
	echo "ln -s ${inputfile} ${inputfile##*/}"                    >> ${jobfile} # create symbolic link to input file with GST naming scheme
    done
    echo "./GetSimpleTuple_data -t${TARNAME} -r${RN}"                 >> ${jobfile} # execute program
    echo "mv -v pruned${TARNAME}_${RN}.root ${OUTDIR}/"               >> ${jobfile} # move outfile to outdir
    echo "rm -v clas_${RN}*.root"                                     >> ${jobfile} # removing symbolic link
    echo ""                                                           >> ${jobfile}	
    echo "Submitting job: ${jobfile}"
    sbatch ${jobfile} # submit job!
done
