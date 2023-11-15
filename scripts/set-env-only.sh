set -e
cd "$(dirname "$0")"/../
export PATH="${PWD}"/crosstool-ng/toolchain/bin:"${PWD}"/mkpsxiso/build:"$PATH"
bash