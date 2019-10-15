FROM hakuyume/chainercv:chainer6.0.0b2-devel
RUN apt-get update -y && apt-get install -y --no-install-recommends \
    ca-certificates \
        cmake \
            curl \
                wget\
                    git \
                        unzip\
                            libopenexr-dev \
                                libpng-dev \
                                    libtiff-dev \
                                        libwebp-dev \
                                            make \
                                                openssh-client \
                                                    python-dev \
                                                        python3-dev \
                                                            zlib1g-dev \
                                                                && apt-get clean \
                                                                    && rm -rf /var/lib/apt/lists/*
