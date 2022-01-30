#!/bin/bash

# 22-01-15
# AOJI by Queue-ri

filepath=`git diff-tree --no-commit-id --name-only -r $3`  # or HEAD~1..HEAD
echo $filepath

cpp_pattern='^.*\.cpp$'
c_pattern='^.*\.c$'
py3_pattern='^.*\.py$'

lang=''

if [[ "$filepath" =~ $cpp_pattern ]]; then
    lang='cpp'
    echo "INFO: C++ file detected."
elif [[ "$filepath" =~ $c_pattern ]]; then
    lang='c'
    echo "INFO: C file detected."
elif [[ "$filepath" =~ $py3_pattern ]]; then
    lang='py3'
    echo "INFO: Python file detected."
else
    echo "INFO: No target file detected."
    exit 0
fi

comment=`git log --format=%B -n 1 $3`
read id perf <<< $(IFS=" "; echo $comment)

perf_pattern='^[0-9]+ms$'

if [[ ! "$perf" =~ $perf_pattern ]]; then
    echo "ERROR: Invalid commit message."
    exit 1
fi

touch .github/aoji_report.md
touch .github/aoji_log.md

printf "\`\`\`\n" > .github/aoji_log.md

python3 -u .github/aoji.py $1 $2 $id $lang $filepath $perf $3 | tee -a .github/aoji_log.md
printf "\`\`\`\n</details>" >> .github/aoji_log.md

cat .github/aoji_log.md >> .github/aoji_report.md

printf "\n<br>\n" >> .github/aoji_report.md
printf "\n**1.0.0-alpha.3** | [Developer](https://github.com/Queue-ri) | [Workflow](https://github.com/Queue-ri/Advanced-Algorithm-Study/commit/$3/checks)" >> .github/aoji_report.md
