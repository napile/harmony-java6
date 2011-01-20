#! /bin/sh

# PMQ_OPTS+=' -Dhy.skip.thr=true'
# PMQ_OPTS+=' -Dskip.native.build=true'
PMQ_OPTS+=' -Dcfg.is.debug=true'
PMQ_OPTS+=' -v'

echo "Running with: $PMQ_OPTS"
./ant.sh ${PMQ_OPTS} $@
