#!/bin/bash
cd "$(dirname "$0")"/../

pandoc -s --template docs/template.html --metadata title="Tonyhax International" readme.md -o readme.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - Playing Games With Additional Anti-Piracy Protection" anti-piracy-bypass.md -o anti-piracy-bypass.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - Save Game Exploit" save-game-exploit.md -o save-game-exploit.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - Flashed Cheat Cartridge/ROM" flashed-cheat-cart.md -o flashed-cheat-cart.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - Boot CD" boot-cd.md -o boot-cd.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - History" changelog.md -o changelog.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - FreePSXBoot Exploit" freepsxboot-exploit.md -o freepsxboot-exploit.html
pandoc -s --template docs/template.html --metadata title="Tonyhax International - GameShark Code Loader" gameshark-code.md -o gameshark-code.html

sed -i 's/anti-piracy-bypass.md/anti-piracy-bypass.html/g' *.html
sed -i 's/save-game-exploit.md/save-game-exploit.html/g' *.html
sed -i 's/flashed-cheat-cart.md/flashed-cheat-cart.html/g' *.html
sed -i 's/boot-cd.md/boot-cd.html/g' *.html
sed -i 's/changelog.md/changelog.html/g' *.html
sed -i 's/freepsxboot-exploit.md/freepsxboot-exploit.html/g' *.html
sed -i 's/gameshark-code.md/gameshark-code.html/g' *.html