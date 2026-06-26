
import yaml

with open("../configuration/setting.yaml", "r", encoding="utf-8") as file:
    data = yaml.safe_load(file)

print(data)
