#!/bin/bash
cd "$(dirname "$0")"
pandoc -s --template ../docs/template.html --metadata title="tonyhax international" ../readme.md -o ../readme.html
