import { Glob } from 'bun';
import { build } from 'esbuild';
import { mkdir } from 'node:fs/promises';

await mkdir('./output/build/library', {
	recursive: true
});

const entry_points = ['index.ts'];

for await (const file of new Glob('**/*.ts').scan('library')) {
	entry_points.push(`library/${file}`);
}

await build({
	entryPoints: entry_points,
	outbase: '.',
	outdir: './output/build',
	bundle: false,
	format: 'esm',
	platform: 'neutral',
	target: 'esnext',
	sourcemap: true
});
