from setuptools import find_packages
from setuptools import setup

setup(
    name='nav2_behavior_plugin',
    version='0.0.0',
    packages=find_packages(
        include=('nav2_behavior_plugin', 'nav2_behavior_plugin.*')),
)
