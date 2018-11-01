import sys
import os

def main():
    os.system("pyinstaller ai.py --name pbrain-LYON-Chaverot.Remy.exe --onefile")
    os.rename("dist/pbrain-LYON-Chaverot.Remy.exe", "pbrain-LYON-Chaverot.Remy.exe")

if __name__ == '__main__':
    main()
