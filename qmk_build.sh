find /Users/stasmarkin/Downloads -name "voyager_sm*" -type f -delete &&
  qmk compile -kb voyager -km sm && \
  mv /Users/stasmarkin/Sync/Projects.IT/qmk_firmware_zsa/voyager_sm.bin \
  /Users/stasmarkin/Downloads/voyager_sm_$(date '+%Y-%m-%d_%H-%M-%S').bin