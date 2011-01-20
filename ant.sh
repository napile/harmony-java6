#!/bin/sh

export ANT_HOME=/usr/local/products/apache-ant-1.8.1
export PATH=$PATH:${ANT_HOME}/bin

ANT_OPTS+=' -Xms256m -Xmx512m'
# ANT_OPTS+=' -v'
export ANT_OPTS

echo "Running ANT with: ${ANT_OPTS}"

TSTAMP=$(date +%Y_%m_%d-%H_%M_%S)
HY_LOGFILE=log.${TSTAMP}
HY_ERRFILE=${HY_LOGFILE}.err

ant $@ 2>${HY_ERRFILE} | tee ${HY_LOGFILE}
