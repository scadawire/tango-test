FROM debian:bullseye

ADD ./cache /usr

ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib
ENV CPATH=$CPATH:/usr/local/include/tango

ENTRYPOINT ["/usr/local/bin/TangoTest"]

CMD ["test", "-ORBendPoint", "giop:tcp::9788", "-nodb", "-dlist", "test/test/1"]